/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:28:09 by jrim              #+#    #+#             */
/*   Updated: 2021/11/29 22:49:13 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    init_detail(t_detail *detail);

void    init_detail(t_detail *detail)
{
    detail->type = 0;
    detail->align = 0;
    detail->padding = 0;
    detail->width = 0;
    detail->prec = 0;
    detail->sp = 0;
    detail->base = 10;
    detail->sign = 1;
}