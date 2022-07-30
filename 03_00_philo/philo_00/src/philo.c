/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 20:48:40 by jrim              #+#    #+#             */
/*   Updated: 2022/07/30 14:54:47 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int init_philo(t_param *param);

int main(int argc, char **argv)
{
    t_param *param;

    param = (t_param *)malloc(1 * sizeof(t_param));
    if (!param)
        err_exit("cannot allocate memory", 12);
    if (parse_param(argc, argv, param) == FAILURE)
        return (1);
    if (init_philo(param) == FAILURE)
        return (1);
    // print_param(param);
    return (0);
}

int init_philo(t_param *param)
{
    t_philo *philo;
    int     idx;

    philo = (t_philo *)malloc(sizeof(t_philo) * param->number_of_philosophers);
    if (philo == NULL)
        err_exit("cannot allocate memory", 12);
    idx = -1;
    while (++idx < param->number_of_philosophers)
    {
        philo[idx].thread = (pthread_t *)malloc(sizeof(pthread_t));
        if (philo[idx].thread == NULL)
            err_exit("cannot allocate memory", 12);
        philo[idx].fork_l = idx;
        philo[idx].fork_r = (idx + 1) % param->number_of_philosophers;
        philo[idx].ms_start = 0;
        philo[idx].ms_end = 0;
        philo[idx].num_eat = 0;
        philo[idx].num_sleep = 0;
    }
    return (SUCCESS);
}