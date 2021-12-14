/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:16:49 by jrim              #+#    #+#             */
/*   Updated: 2021/12/14 19:13:12 by jrim             ###   ########.fr       */
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
	char		*str;
	int			str_len;
	int			ret_len;

	num = va_arg(ap, int);
	if (num < 0)
		detail->sign = '-';
	num *= (num > 0) - (num < 0);
	str = ft_itoa_base(detail, num, DEC);
	str_len = ft_strlen(str);
	ret_len = parse_numlen(detail, &str_len);
	if (detail->align == RIGHT)
    	fill_str(detail, detail->wid - ret_len, 0);
	print_sign(detail);
	fill_str(detail, detail->prec - ft_strlen(str), detail->pad);
	write(1, str, ft_strlen(str));
	if (detail->align != RIGHT)
    	fill_str(detail, detail->wid - ret_len, 0);
	free(str);
	if (ret_len < detail->wid)
		ret_len = detail->wid;
	return (ret_len);
}

int	print_uns(t_detail *detail, va_list ap)
{
	unsigned int	num;
	char			*str;
	int				str_len;
	int				ret_len;

	num = va_arg(ap, unsigned int);
	str = ft_itoa_base(detail, num, DEC);
	str_len = ft_strlen(str);
	ret_len = parse_numlen(detail, &str_len);
	if (ret_len < detail->wid)
		ret_len = detail->wid;
	if (detail->align == RIGHT)
		fill_str(detail, ret_len - str_len, detail->pad);
	write(1, str, ft_strlen(str));
	if (detail->align != RIGHT)
		fill_str(detail, ret_len - str_len, 0);
	free(str);
	return (ret_len);
}

int	print_hex(t_detail *detail, va_list ap)
{
	long long	num;
	char		*str;
	int			str_len;
	int			ret_len;

	detail->base = 16;
	if (detail->type == 'p')
		num = (unsigned long)va_arg(ap, void *);
	else
		num = va_arg(ap, unsigned int);
	str = ft_itoa_base(detail, num, HEX);
	str_len = ft_strlen(str);
	ret_len = parse_numlen(detail, &str_len);
	if (detail->align == RIGHT)
    	fill_str(detail, detail->wid - ret_len, 0);
	print_alt(detail);
	fill_str(detail, detail->prec - ft_strlen(str), detail->pad);
	write(1, str, ft_strlen(str));
	if (detail->align != RIGHT)
    	fill_str(detail, detail->wid - ret_len, 0);
	free(str);
	if (ret_len < detail->wid)
		ret_len = detail->wid;
	return (ret_len);
}

char	*ft_itoa_base(t_detail *detail, unsigned long num, char *base)
{
	size_t	base_len;
	size_t	idx;
	char	*str;

	if (detail->type != 'p' && num == 0)
		detail->alt = OFF;
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
