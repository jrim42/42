/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _utils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 21:11:59 by jrim              #+#    #+#             */
/*   Updated: 2022/03/02 14:36:21 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    err_display(int err_type);

void    err_display(int err_type)
{
    if (err_type < 2)
        ft_putstr_fd("usage : ./server [no arg needed]", 1);
    else
        ft_putstr_fd("error : ", 1);
    if (err_type == 0)
        ft_putendl_fd("./client [server pid] [message to send]", 1);
    else if (err_type == 1)
        ft_putendl_fd("./server [no arg needed]", 1);
    else if (err_type == 2)
        ft_putendl_fd("error type 2", 1);
    ft_putstr_fd("\n", 1);
    exit(1);
}
