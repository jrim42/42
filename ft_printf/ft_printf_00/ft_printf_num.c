/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:16:49 by jrim              #+#    #+#             */
/*   Updated: 2021/12/09 14:56:18 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_int(t_detail *detail, va_list ap);
int		parse_hex(t_detail *detail, va_list ap);
int		print_num(t_detail *detail, char *str);
char	*ft_itoa_base(t_detail *detail, unsigned long num, char *base);
int		numlen_base(unsigned long num, int base_len);

int	parse_int(t_detail *detail, va_list ap)
{
	long long	num;
	int			len;
	char		*str;

	if (detail->type == 'd' || detail->type == 'i')
	{
		num = va_arg(ap, int);
		if (num < 0)
			detail->sign = '-';
		num *= (num > 0) - (num < 0);
		str = ft_itoa_base(detail, num, DEC);
	}
	else
	{
		num = va_arg(ap, unsigned int);
		str = ft_itoa_base(detail, num, DEC);
	}
	len = print_num(detail, str);
	free(str);
	return (len);
}

int	parse_hex(t_detail *detail, va_list ap)
{
	long long	num;
	int			len;
	char		*str;

	detail->base = 16;
	detail->sign = OFF;
	if (detail->type == 'x' || detail->type == 'X')
	{
		num = va_arg(ap, unsigned int);
		str = ft_itoa_base(detail, num, HEX);
	}
	else
	{
		detail->alt = 2;
		num = (unsigned long)va_arg(ap, void *);
		str = ft_itoa_base(detail, num, HEX);
	}
	len = print_num(detail, str);
	free(str);
	return (len);
}

int	print_num(t_detail *detail, char *str)
{
	int	str_len;
	
	str_len = ft_strlen(str);
	if (detail->sign != OFF)
	{
		str_len++;
		write(1, "-", 1);
	}
	else if (detail->alt != OFF)
	{
		str_len += 2;
		write(1, "0x", 2);
	}
	write(1, str, ft_strlen(str));
	return (str_len);
}


char	*ft_itoa_base(t_detail *detail, unsigned long num, char *base)
{
	int		base_len;
	int		idx;
	char	*str;

	base_len = detail->base;
	idx = numlen_base(num, base_len) + 1;
	str = (char *)malloc(idx * sizeof(char));
	if (!str)
		return (0);
	str[0] = '0';
	str[--idx] = '\0';
	while (idx-- > 0 && num > 0)
	{
		str[idx] = base[num % base_len];
		num /= base_len;
	}
	if (detail->type == 'X')
		while (str[++idx])
			str[idx] = ft_toupper(str[idx]);
	return (str);
}

int	numlen_base(unsigned long num, int base_len)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		len++;
		num /= base_len;
	}
	return (len);
}