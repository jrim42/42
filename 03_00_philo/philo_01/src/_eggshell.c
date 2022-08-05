/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _eggshell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 22:25:00 by jrim              #+#    #+#             */
/*   Updated: 2022/08/05 13:24:40 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_philos_stuffed(t_info *info);
int	is_philo_dead(t_info *info, t_philo *philo);

int	eggshell(t_info *info)
{
	int	idx;

	while (info->is_done == UNDONE)
	{
		idx = -1;
		while (++idx < info->param.num_philo)
		{
			if (is_philo_dead(info, &(info->philos[idx])) == DONE)
				return (DONE);
		}
		if (is_philos_stuffed(info) == DONE)
			return (DONE);
	}
	return (UNDONE);
}

int	is_philos_stuffed(t_info *info)
{
	if (info->stuffed_philo == info->param.num_philo)
	{
		pthread_mutex_lock(&(info->print_mtx));
		info->is_done = DONE;
		pthread_mutex_unlock(&(info->philo_mtx));
		return (DONE);
	}
	return (UNDONE);
}

int	is_philo_dead(t_info *info, t_philo *philo)
{
	struct timeval	now;
	long long		interval;

	gettimeofday(&now, NULL);
	interval = get_time_interval(now, philo->last_eat);
	if (interval >= philo->info->param.ms_to_die)
	{
		pthread_mutex_lock(&(info->print_mtx));
		gettimeofday(&now, NULL);
		interval = get_time_interval(now, info->birthday);
		printf("%llums\t%d\tdied\n", interval, philo->name);
		info->is_done = DONE;
		pthread_mutex_unlock(&(info->philo_mtx));
		return (DONE);
	}
	return (UNDONE);
}
