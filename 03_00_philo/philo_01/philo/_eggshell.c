/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _eggshell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 22:25:00 by jrim              #+#    #+#             */
/*   Updated: 2022/08/09 23:47:01 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_philo_dead(t_info *info, t_philo *philo);
int	is_philos_stuffed(t_info *info);

void	eggshell(t_info *info)
{
	int	idx;
	int	min;

	while (info->is_done == UNDONE)
	{
		idx = -1;
		min = info->param.n_eat;
		while (++idx < info->param.n_philo)
		{
			is_philo_dead(info, &(info->philos[idx]));
			if (min > info->philos[idx].eat_cnt)
				min = info->philos[idx].eat_cnt;
			if (info->is_done == DONE)
				break ;
		}
		if (min >= info->param.n_eat || info->is_done == DONE)
			info->is_done = DONE;
	}
	return ;
}

// void	eggshell(t_info *info)
// {
// 	int	idx;

// 	while (info->is_done == UNDONE)
// 	{
// 		idx = -1;
// 		while (++idx < info->param.n_philo)
// 		{
// 			if (is_philo_dead(info, &(info->philos[idx])) == DONE)
// 				break ;
// 		}
// 		is_philos_stuffed(info);
// 	}
// 	return ;
// }

int	is_philo_dead(t_info *info, t_philo *philo)
{
	struct timeval	now;
	long long		interval;

	gettimeofday(&now, NULL);
	interval = get_time_interval(now, philo->last_eat);
	if (interval >= philo->info->param.ms_die)
	{
		gettimeofday(&now, NULL);
		interval = get_time_interval(now, info->birthday);
		print_routine(philo, "is died");
		info->is_done = DONE;
		// pthread_mutex_unlock(&(info->philo_mtx));
		return (DONE);
	}
	return (UNDONE);
}

int	is_philos_stuffed(t_info *info)
{
	if (info->stuffed_philo == info->param.n_philo)
	{
		info->is_done = DONE;
		pthread_mutex_unlock(&(info->philo_mtx));
		// pthread_mutex_lock(&(info->msg_mtx));
		return (DONE);
	}
	return (UNDONE);
}
