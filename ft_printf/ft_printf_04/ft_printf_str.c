/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:17:04 by jrim              #+#    #+#             */
/*   Updated: 2021/12/20 00:14:54 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_str(t_detail *detail, va_list ap);
int		print_str(t_detail *detail, int ch, const char *str);
int		print_else(t_detail *detail, int ch);
int		parse_strlen(t_detail *detail);

int	parse_str(t_detail *detail, va_list ap)
{
	int			ch;
	const char	*str;
	int			len;

	ch = 0;
	str = 0;
	if (detail->type == 'c')
	{
		ch = va_arg(ap, int);
		detail->str_len = 1;
	}
	else if (detail->type == '%')
	{
		ch = '%';
		detail->str_len = 1;
	}
	if (detail->type == 's')
	{
		str = va_arg(ap, char *);
		if (!str)
			str = "(null)";
		detail->str_len = ft_strlen(str);
	}
	len = print_str(detail, ch, str);
	return (len);
}

int	print_str(t_detail *detail, int ch, const char *str)
{
	int			ret_len;

	ret_len = parse_strlen(detail);
	if (detail->align == RIGHT)
		fill_width(detail, ret_len - detail->str_len, detail->pad);
	if (detail->type == 's')
		write(1, str, detail->str_len);
	else
		write(1, &ch, 1);
	if (detail->align != RIGHT)
		fill_width(detail, ret_len - detail->str_len, 0);
	return (ret_len);
}

int	print_else(t_detail *detail, int ch)
{
	int	ret_len;

	detail->str_len = 1;
	ret_len = parse_strlen(detail);
	if (detail->align == RIGHT)
		fill_width(detail, ret_len - detail->str_len, detail->pad);
	write(1, &ch, 1);
	if (detail->align != RIGHT)
		fill_width(detail, ret_len - detail->str_len, 0);
	return (ret_len);
}

int	parse_strlen(t_detail *detail)
{
	int		ret_len;

	if (detail->type == 's')
		if (detail->prec != -1 && detail->prec < detail->str_len)
			detail->str_len = detail->prec;
	ret_len = detail->str_len;
	if (ret_len < detail->wid)
		ret_len = detail->wid;
	return (ret_len);
}
