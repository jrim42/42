/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _monitor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 22:25:00 by jrim              #+#    #+#             */
/*   Updated: 2022/08/18 01:03:24 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_philo_dead(t_info *info, t_philo *philo);
int	is_philo_full(t_info *info, int min_eat);

void	monitor(t_info *info)
{
	int	idx;
	int	min_eat;

	pthread_mutex_lock(&(info->main_mtx));
	while (info->is_done == UNDONE)
	{
		pthread_mutex_unlock(&(info->main_mtx));
		idx = -1;
		min_eat = info->param.n_eat;
		while (++idx < info->param.n_philo)
		{
			if (is_philo_dead(info, &(info->philos[idx])) == DEAD)
				return ;
			pthread_mutex_lock(&(info->philos[idx].eat_mtx));
			if (min_eat > info->philos[idx].eat_cnt)
				min_eat = info->philos[idx].eat_cnt;
			pthread_mutex_unlock(&(info->philos[idx].eat_mtx));
			usleep(100);
		}
		if (is_philo_full(info, min_eat) == 1)
			return ;
		pthread_mutex_lock(&(info->main_mtx));
	}
	pthread_mutex_unlock(&(info->main_mtx));
}

int	is_philo_dead(t_info *info, t_philo *philo)
{
	struct timeval	now;
	long long		interval;

	pthread_mutex_lock(&(info->main_mtx));
	if (info->is_done == DONE)
	{
		pthread_mutex_unlock(&(info->main_mtx));
		return (DONE);
	}
	pthread_mutex_unlock(&(info->main_mtx));
	pthread_mutex_lock(&(philo->eat_mtx));
	if (philo->is_dead != DEAD)
	{
		gettimeofday(&now, NULL);
		interval = get_time_interval(now, philo->last_eat);
		if (interval >= philo->info->param.ms_die)
		{
			philo->is_dead = DEAD;
			print_dead(philo, info);
			pthread_mutex_unlock(&(philo->eat_mtx));
			pthread_mutex_lock(&(info->main_mtx));
			info->is_done = DONE;
			pthread_mutex_unlock(&(info->main_mtx));
			return (DEAD);
		}
	}
	pthread_mutex_unlock(&(philo->eat_mtx));
	return (ALIVE);
}

int	is_philo_full(t_info *info, int min_eat)
{
	int	flag;

	flag = 0;
	if (min_eat >= info->param.n_eat)
	{
		pthread_mutex_lock(&(info->main_mtx));
		info->is_done = DONE;
		pthread_mutex_unlock(&(info->main_mtx));
		flag = 1;
	}
	return (flag);
}
