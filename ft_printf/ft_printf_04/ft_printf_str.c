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
void	print_str(t_detail *detail, int ch, const char *str);
int		print_else(t_detail *detail, int ch);
void	parse_strlen(t_detail *detail);

int	parse_str(t_detail *detail, va_list ap)
{
	int			ch;
	const char	*str;

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
	print_str(detail, ch, str);
	return (detail->ret_len);
}

void	print_str(t_detail *detail, int ch, const char *str)
{
	parse_strlen(detail);
	if (detail->align == RIGHT)
		fill_width(detail, detail->ret_len - detail->str_len, detail->pad);
	if (detail->type == 's')
		write(1, str, detail->str_len);
	else
		write(1, &ch, 1);
	if (detail->align != RIGHT)
		fill_width(detail, detail->ret_len - detail->str_len, 0);
}

int	print_else(t_detail *detail, int ch)
{
	detail->str_len = 1;
	parse_strlen(detail);
	if (detail->align == RIGHT)
		fill_width(detail, detail->ret_len - detail->str_len, detail->pad);
	write(1, &ch, 1);
	if (detail->align != RIGHT)
		fill_width(detail, detail->ret_len - detail->str_len, 0);
	return (detail->ret_len);
}

void	parse_strlen(t_detail *detail)
{
	if (detail->type == 's')
		if (detail->prec != -1 && detail->prec < detail->str_len)
			detail->str_len = detail->prec;
	detail->ret_len = detail->str_len;
	if (detail->ret_len < detail->wid)
		detail->ret_len = detail->wid;
}
