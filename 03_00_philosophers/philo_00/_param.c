/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _parse_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:55:41 by jrim              #+#    #+#             */
/*   Updated: 2022/05/18 17:20:05 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int     parse_param(int argc, char **argv, t_param *param);
int     _check_arg(int argc, char **argv);
void    _get_param(int argc, char **argv, t_param *param);

int parse_param(int argc, char **argv, t_param *param)
{
    if (argc < 5 && argc > 6)
    {
        printf("invalid param number\n");
        return (0);
    }
    if (_check_arg(argc, argv) == 0)
    {
        printf("invalid character in params\n");
        return (0);
    }
    _get_param(argc, argv, param);
    return (0);
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
            if (ft_strchr(NUM, argv[idx1][idx2]) == 0)
                return (0);
    }
    return (1);
}

void    _get_param(int argc, char **argv, t_param *param)
{
    param->number_of_philosophers = ft_atoi(argv[1]);
    param->time_to_die = ft_atoi(argv[2]);
    param->time_to_eat = ft_atoi(argv[3]);
    param->time_to_sleep = ft_atoi(argv[4]);
    if (argc == 6)
        param->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
    else
        param->number_of_times_each_philosopher_must_eat = -1;
}