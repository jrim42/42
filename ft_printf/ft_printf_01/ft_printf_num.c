/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:16:49 by jrim              #+#    #+#             */
/*   Updated: 2021/12/04 17:36:17 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_int(t_detail *detail, va_list ap);
int		print_uns(t_detail *detail, va_list ap);
int		print_hex(t_detail *detail, va_list ap);
char	*ft_itoa_base(t_detail *detail, unsigned long num, char *base);
size_t	numlen_base(unsigned long num, size_t base_len);

int	print_int(t_detail *detail, va_list ap)
{
	long long	num;
	int			len;
	char		*str;

	num = va_arg(ap, int);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	str = ft_itoa(num);
	len = ft_strlen(str);
	if (len < detail->wid)
		len = detail->wid;
	if (detail->align == LEFT)
		write(1, str, ft_strlen(str));
	print_width(detail, ft_strlen(str));
	if (detail->align == RIGHT)
		write(1, str, ft_strlen(str));
	free(str);
	return (len);
}

int	print_uns(t_detail *detail, va_list ap)
{
	long long	num;
	int			len;
	char		*str;

	num = va_arg(ap, int);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	else if (num < 0)
		num = (unsigned int)num;
	str = ft_itoa(num);
	len = ft_strlen(str);
	if (len < detail->wid)
		len = detail->wid;
	if (detail->align == LEFT)
		write(1, str, ft_strlen(str));
	print_width(detail, ft_strlen(str));
	if (detail->align == RIGHT)
		write(1, str, ft_strlen(str));
	free(str);
	return (len);
}

int	print_hex(t_detail *detail, va_list ap)
{
	long long	num;
	int			len;
	char		*str;

	detail->base = 16;
	if (detail->type == 'p')
	{
		num = (unsigned long)va_arg(ap, void *);
		detail->alt = 2;
	}	
	else
	{
		num = va_arg(ap, int);
		if (num > INT_MAX)
			return (0);
		else if (num < 0)
			num = (unsigned int)num;
		if (num == 0)
			detail->alt = OFF;
	}
	str = ft_itoa_base(detail, num, HEX);
	len = ft_strlen(str) + detail->alt;
	if (detail->pad == OFF)
		print_width(detail, len);
	print_alt(detail);
	if (detail->pad == ON)
		print_width(detail, len);
	write(1, str, ft_strlen(str));
	free(str);
	if (len < detail->wid)
		len = detail->wid;
	return (len);
}

char	*ft_itoa_base(t_detail *detail, unsigned long num, char *base)
{
	size_t	base_len;
	size_t	idx;
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

size_t	numlen_base(unsigned long num, size_t base_len)
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
