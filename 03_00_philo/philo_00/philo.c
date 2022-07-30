/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 20:48:40 by jrim              #+#    #+#             */
/*   Updated: 2022/07/30 14:42:41 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    print_param(t_param *param);

int main(int argc, char **argv)
{
    t_param *param;

    param = (t_param *)malloc(1 * sizeof(t_param));
    if (!param)
        err_exit("cannot allocate memory", 12);
    if (parse_param(argc, argv, param) == FAILURE)
        return (1);
    print_param(param);
    return (0);
}
