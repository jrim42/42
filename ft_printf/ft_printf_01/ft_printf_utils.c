/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:28:09 by jrim              #+#    #+#             */
/*   Updated: 2021/12/08 22:16:53 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_width(t_detail *detail, int len);
void	print_alt(t_detail *detail);
int		parse_len(t_detail *detail, int	str_len);

void	print_width(t_detail *detail, int len)
{
	int	cnt;
	int	line_wid;

	if (detail->wid > detail->prec)
		line_wid = detail->wid;
	else
		line_wid = detail->prec + detail->minus;
	cnt = line_wid - len;
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

int	parse_len(t_detail *detail, int	str_len)
{
	int	len;
	int	line_wid;

	line_wid = 0;
	// if (detail->type != 'x' || detail->type != 'X' || detail->type != 'p')
	// 	detail->alt = OFF;
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
