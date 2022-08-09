/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _eggshell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 22:25:00 by jrim              #+#    #+#             */
/*   Updated: 2022/08/10 00:31:03 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_philo_dead(t_info *info, t_philo *philo);

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
		return (DONE);
	}
	return (UNDONE);
}
