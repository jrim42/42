/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:28:09 by jrim              #+#    #+#             */
/*   Updated: 2021/12/04 00:42:59 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_detail(t_detail *detail)
{
	detail->type = 0;
	detail->align = LEFT;
	detail->pad = OFF;
	detail->sp = OFF;
	detail->prec = OFF;
	detail->wid = OFF;
	detail->alt = OFF;
	detail->sign = 1;
	detail->base = 10;
}

void	print_width(t_detail *detail, int len)
{
	int	cnt;

	cnt = detail->wid - len;
	if (detail->pad == OFF)
		while (cnt-- > 0)
			write(1, " ", 1);
	else
		while (cnt-- > 0)
			write(1, "0", 1);
}
