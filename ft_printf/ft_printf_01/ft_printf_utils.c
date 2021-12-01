/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:28:09 by jrim              #+#    #+#             */
/*   Updated: 2021/12/01 18:20:25 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    init_detail(t_detail *detail)
{
    detail->type = 0;
    detail->adj = OFF;
    detail->pad = OFF;
    detail->prec = OFF;
    detail->sp = OFF;
    detail->wid = OFF;
    detail->alt = OFF;
    detail->sign = 1;
    detail->base = 10; 
}