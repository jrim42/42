/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:16:49 by jrim              #+#    #+#             */
/*   Updated: 2021/12/20 00:28:13 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_int(t_detail *detail, va_list ap);
int		parse_hex(t_detail *detail, va_list ap);
int		print_num(t_detail *detail, char *str);
int		parse_numlen(t_detail *detail);

int	parse_int(t_detail *detail, va_list ap)
{
	long long	num;
	char		*str;
	int			len;

	detail->alt = OFF;
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
	int			len;
	long long	num;
	char		*str;

	len = 0;
	detail->base = 16;
	detail->sign = OFF;
	if (detail->type == 'x' || detail->type == 'X')
	{
		num = va_arg(ap, unsigned int);
		if (num == 0)
			detail->alt = OFF;
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
	int			ret_len;

	detail->str_len = ft_strlen(str);
	ret_len = parse_numlen(detail);
	if (detail->align == RIGHT)
		fill_width(detail, detail->wid - ret_len, 0);
	print_sign(detail);
	fill_prec(detail, detail->prec - ft_strlen(str), ret_len, detail->pad);
	write(1, str, ft_strlen(str));
	if (detail->align != RIGHT)
		fill_width(detail, detail->wid - ret_len, 0);
	if (ret_len < detail->wid)
		ret_len = detail->wid;
	return (ret_len);
}

int	parse_numlen(t_detail *detail)
{
	int		sign_len;
	int		ret_len;

	sign_len = 0;
	ret_len = detail->str_len;
	if (detail->prec != -1 && detail->prec > detail->str_len)
		ret_len = detail->prec;
	if (detail->sign != OFF)
		sign_len += 1;
	if (detail->alt != OFF)
		sign_len += detail->alt;
	ret_len += sign_len;
	detail->str_len += sign_len;
	return (ret_len);
}
