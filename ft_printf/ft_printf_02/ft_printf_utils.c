/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:28:09 by jrim              #+#    #+#             */
/*   Updated: 2021/12/10 13:48:50 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_width(t_detail *detail, int str_len, int ret_len);
void	print_alt(t_detail *detail);
void	print_sign(t_detail *detail);
int		parse_numlen(t_detail *detail, int str_len);
int		parse_strlen(t_detail *detail, int *str_len);

void	print_width(t_detail *detail, int str_len, int ret_len)
{
	int	cnt;

	cnt = ret_len - str_len;
	if (detail->pad == OFF)
		while (cnt-- > 0)
			write(1, " ", 1);
	else if (detail->align != LEFT)
		while (cnt-- > 0)
			write(1, "0", 1);
}

void	print_alt(t_detail *detail)
{
	if (detail->alt == 2)
	{
		if (detail->type == 'X')
			write(1, "0X", 2);
		else if (detail->type == 'x' || detail->type == 'p')
			write(1, "0x", 2);
	}
}

void	print_sign(t_detail *detail)
{
	if (detail->minus == ON)
		write(1, "-", 1);
	else if (detail->plus == ON)
		write(1, "+", 1);
	else if (detail->sp == ON)
		write(1, " ", 1);
}

int	parse_numlen(t_detail *detail, int str_len)
{
	int		len;
	int		line_wid;

	line_wid = 0;
	len = str_len + detail->sp + detail->plus - detail->minus;
	if (!detail->sp && detail->minus)
		len++;
	if (detail->wid > detail->prec)
		line_wid = detail->wid;
	else
		line_wid = detail->prec + detail->minus;
	if (len < line_wid)
		len = line_wid;
	return (len);
}

int		parse_strlen(t_detail *detail, int *str_len)
{
	int	ret_len;

	if (detail->type == 's')
		if (detail->prec != -1 && detail->prec < *str_len)
			*str_len = detail->prec;
	ret_len = *str_len;
	if (ret_len < detail->wid)
		ret_len = detail->wid;
	return (ret_len);
}