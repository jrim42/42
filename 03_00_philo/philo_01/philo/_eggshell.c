/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _eggshell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 22:25:00 by jrim              #+#    #+#             */
/*   Updated: 2022/08/10 18:47:27 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_philo_dead(t_info *info, t_philo *philo);

void	eggshell(t_info *info)
{
	int	idx;
	int	min_eat;

	while (info->is_done == UNDONE)
	{
		idx = -1;
		min_eat = info->param.n_eat;
		while (++idx < info->param.n_philo)
		{
			is_philo_dead(info, &(info->philos[idx]));
			if (min_eat > info->philos[idx].eat_cnt)
				min_eat = info->philos[idx].eat_cnt;
			if (info->is_done == DONE)
				break ;
		}
		if (min_eat >= info->param.n_eat || info->is_done == DONE)
		{
			info->is_done = DONE;
			pthread_mutex_unlock(&(info->main_mtx));
		}
	}
	return ;
}

int	is_philo_dead(t_info *info, t_philo *philo)
{
	struct timeval	now;
	long long		interval;

	gettimeofday(&now, NULL);
	interval = get_time_interval(now, philo->last_eat);
	if (interval >= philo->info->param.ms_die)
	{
		info->is_done = DONE;
		gettimeofday(&now, NULL);
		interval = get_time_interval(now, info->birthday);
		pthread_mutex_lock(&(philo->info->msg_mtx));
		printf("%llums\t%d\tis died\n", interval, philo->name);
		pthread_mutex_unlock(&(philo->info->msg_mtx));
		pthread_mutex_unlock(&(info->main_mtx));
		return (DONE);
	}
	return (UNDONE);
}
