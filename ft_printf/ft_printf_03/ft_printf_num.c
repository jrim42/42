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
int		parse_numlen(t_detail *detail, int *str_len);

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
    	fill_width(detail, detail->wid - ret_len, 0);
	// print_sign(detail);
	if (detail->sign != OFF)
		write(1, &detail->sign, 1);
	fill_prec(detail, detail->prec - ft_strlen(str), ret_len, detail->pad);
	write(1, str, ft_strlen(str));
	if (detail->align != RIGHT)
    	fill_width(detail, detail->wid - ret_len, 0);
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
		fill_width(detail, ret_len - str_len, detail->pad);
	write(1, str, ft_strlen(str));
	if (detail->align != RIGHT)
		fill_width(detail, ret_len - str_len, 0);
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
    	fill_width(detail, detail->wid - ret_len, 0);
	print_alt(detail);
	fill_prec(detail, detail->prec - ft_strlen(str), ret_len, detail->pad);
	write(1, str, ft_strlen(str));
	if (detail->align != RIGHT)
    	fill_width(detail, detail->wid - ret_len, 0);
	free(str);
	if (ret_len < detail->wid)
		ret_len = detail->wid;
	return (ret_len);
}

int	parse_numlen(t_detail *detail, int *str_len)
{
	int		ret_len;

	ret_len = *str_len;
	if (detail->prec != -1 && detail->prec > *str_len)
		ret_len = detail->prec;
	if (detail->type == 'p' || detail->type == 'x' || detail->type == 'X')
	{
		ret_len += detail->alt;
		*str_len += detail->alt;
	}
	else if (detail->type == 'd' || detail->type == 'i')
		if (detail->sign != OFF)
		{
			ret_len += 1;
			*str_len += 1;
		}
	return (ret_len);
}
