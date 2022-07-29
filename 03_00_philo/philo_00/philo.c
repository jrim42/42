/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 20:48:40 by jrim              #+#    #+#             */
/*   Updated: 2022/05/18 17:09:47 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
    t_param *param;

    param = (t_param *)malloc(1 * sizeof(t_param));
    if (!param)
        return (1);
    if (parse_param(argc, argv, param) == 0)
        return (1);
    return (0);
}