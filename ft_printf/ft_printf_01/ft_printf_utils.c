/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:28:09 by jrim              #+#    #+#             */
/*   Updated: 2021/12/01 19:18:17 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_detail(t_detail *detail)
{
	detail->type = 0;
	detail->adj = OFF;
	detail->pad = OFF;
	detail->sp = OFF;
	detail->prec = OFF;
	detail->wid = OFF;
	detail->alt = OFF;
	detail->sign = 1;
	detail->base = 10;
}

// void	init_diu(t_detail *detail)
// {
// 	detail->type = 0;
// 	detail->adj = OFF;
// 	detail->pad = OFF;
// 	detail->sp = OFF;
// 	detail->prec = OFF;
// 	detail->wid = OFF;
// 	detail->alt = OFF;
// 	detail->sign = 1;
// 	detail->base = 10;
// }

// void	init_cs(t_detail *detail)
// {
// 	detail->type = 0;
// 	detail->adj = OFF;
// 	detail->pad = IGNORED;
// 	detail->sp = OFF;
// 	detail->prec = OFF;
// 	detail->wid = OFF;
// 	detail->alt = IGNORED;
// 	detail->sign = IGNORED;
// 	detail->base = IGNORED;
// }

// void	init_xXp(t_detail *detail)
// {
// 	detail->type = 0;
// 	detail->adj = OFF;
// 	detail->pad = OFF;
// 	detail->sp = OFF;
// 	detail->prec = OFF;
// 	detail->wid = OFF;
// 	detail->alt = OFF;
// 	detail->sign = 1;
// 	detail->base = 16;
// }