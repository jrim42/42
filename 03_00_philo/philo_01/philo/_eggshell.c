/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _eggshell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 22:25:00 by jrim              #+#    #+#             */
/*   Updated: 2022/08/05 16:19:06 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_philos_stuffed(t_info *info);
int	is_philo_dead(t_info *info, t_philo *philo);

void	eggshell(t_info *info)
{
	int				idx;

	while (info->is_done == UNDONE)
	{
		idx = -1;
		while (++idx < info->param.n_philo)
		{
			if (is_philo_dead(info, &(info->philos[idx])) == DONE)
				return ;
		}
		if (is_philos_stuffed(info) == DONE)
			return ;
	}
	return ;
}

int	is_philos_stuffed(t_info *info)
{
	if (info->stuffed_philo == info->param.n_philo)
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
	if (interval >= philo->info->param.t_die)
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
