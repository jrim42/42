/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 20:48:40 by jrim              #+#    #+#             */
/*   Updated: 2022/07/31 22:15:02 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philo(t_philo *philo, t_param *param, pthread_mutex_t *fork);

int	main(int argc, char **argv)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (info == NULL)
		print_error("cannot allocate memory", 12);
	if (parse_param(argc, argv, info->param) == FAILURE)
		return (1);
	if (init_philo(info->philo, info->param, info->fork) == FAILURE)
		return (1);
	// print_param(param);
	return (0);
}

int	init_philo(t_philo *philo, t_param *param, pthread_mutex_t *fork)
{
	int	idx;

	philo = (t_philo *)malloc(sizeof(t_philo) * param->num_philo);
	fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * param->num_philo);
	if (philo == NULL || fork == NULL)
		print_error("cannot allocate memory", 12);
	idx = -1;
	while (++idx < param->num_philo)
	{
		// philo[idx].thread = (pthread_t *)malloc(sizeof(pthread_t));
		// if (philo[idx].thread == NULL)
		//     err_exit("cannot allocate memory", 12);
		// fork init 과 philo init을 구분할까?
		pthread_mutex_init(&fork[idx], NULL);
		philo[idx].fork_l = idx;
		philo[idx].fork_r = (idx + 1) % param->num_philo;
		philo[idx].ms_start = 0;
		philo[idx].ms_end = 0;
		philo[idx].num_eat = 0;
		philo[idx].num_sleep = 0;
	}
	return (SUCCESS);
}
