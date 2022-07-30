/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _param.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:55:41 by jrim              #+#    #+#             */
/*   Updated: 2022/07/30 14:46:10 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int     parse_param(int argc, char **argv, t_param *param);
int     _check_arg(int argc, char **argv);

int parse_param(int argc, char **argv, t_param *param)
{
    if (argc < 5 || argc > 6)
        err_exit("invalid param number", 1);
    if (_check_arg(argc, argv) == INVALID)
        err_exit("invalid character in params", 1);
    param->number_of_philosophers = ft_atoi(argv[1]);
    // fork num?
    param->time_to_die = ft_atoi(argv[2]);
    param->time_to_eat = ft_atoi(argv[3]);
    param->time_to_sleep = ft_atoi(argv[4]);
    if (argc == 6)
        param->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
    else
        param->number_of_times_each_philosopher_must_eat = -1;
    return (SUCCESS);
}

int     _check_arg(int argc, char **argv)
{
    int idx1;
    int idx2;

    idx1 = 0;
    while (++idx1 < argc)
    {
        idx2 = -1;
        while (argv[idx1][++idx2])
        {
            // while (ft_strchr(WH_SP, argv[idx1][idx2]))
            //     idx2++;
            if (ft_strchr(NUM, argv[idx1][idx2]) == 0)
                return (INVALID);
        }
    }
    return (VALID);
}
