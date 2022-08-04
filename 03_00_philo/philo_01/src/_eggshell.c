/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _eggshell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 22:25:00 by jrim              #+#    #+#             */
/*   Updated: 2022/08/04 20:13:07 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_philo_dead(t_info *info, t_philo *philo);

void	*eggshell(void	*void_info)
{
	t_info			*info;
	int				idx;

	info = (t_info *)void_info;
	while (info->is_done == UNDONE)
	{
		if (info->stuffed_philo == info->param.num_philo)
		{
			pthread_mutex_lock(&(info->print_mtx));
			printf("\n*** all philos have got enough meals ***\n");
			usleep(100);
			info->is_done = DONE;
			pthread_mutex_unlock(&(info->philo_mtx));
			return (NULL);
		}
		idx = -1;
		while (++idx < info->param.num_philo)
		{
			if (is_philo_dead(info, &(info->philos[idx])) == 1)
				return (NULL);
		}
		usleep(200);
	}
	return (NULL);
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
		usleep(100);
		info->is_done = DONE;
		pthread_mutex_unlock(&(info->philo_mtx));
		return(1);
	}
	return (0);
}