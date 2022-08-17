/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _eggshell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 22:25:00 by jrim              #+#    #+#             */
/*   Updated: 2022/08/18 01:03:24 by jrim             ###   ########.fr       */
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
			if (is_philo_dead(info, &(info->philos[idx])) == DONE)
				return ;
			if (min_eat > info->philos[idx].eat_cnt)
				min_eat = info->philos[idx].eat_cnt;
			usleep(100);
		}
		if (min_eat >= info->param.n_eat)
		{
			info->is_done = DONE;
			pthread_mutex_unlock(&(info->main_mtx));
			return ;
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
		pthread_mutex_lock(&(philo->info->msg_mtx));
		gettimeofday(&now, NULL);
		interval = get_time_interval(now, info->birthday);
		printf("%llums\t%d\tis died\n", interval, philo->name);
		// printf("\033[0;31m%llu\t%d\tis died\033[0;37m\n", interval, philo->name);
		// printf("\033[0;31m%llums\t%d\tis died\033[0;37m\n", interval, philo->name);
		// pthread_mutex_unlock(&(philo->info->msg_mtx));
		pthread_mutex_unlock(&(info->main_mtx));
		return (DONE);
	}
	return (UNDONE);
}
