/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _utils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 21:11:59 by jrim              #+#    #+#             */
/*   Updated: 2022/02/26 21:15:26 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    err_display(int err_type)
{
    ft_putstr_fd("error : ", 1);
    if (err_type == 0)
        ft_putendl_fd("error type 0", 1);
    else if (err_type == 1)
        ft_putendl_fd("error type 1", 1);
    else if (err_type == 2)
        ft_putendl_fd("error type 2", 1);
    ft_putstr_fd("\n", 1);
}