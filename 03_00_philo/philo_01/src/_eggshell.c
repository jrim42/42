/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _eggshell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 22:25:00 by jrim              #+#    #+#             */
/*   Updated: 2022/08/04 15:49:06 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*eggshell(void	*void_info)
{
	t_info			*info;
	int				idx;
	struct timeval	now;
	long long		interval;
	t_philo			*philo;

	info = (t_info *)void_info;
	idx = 0;
	while (info->is_done == UNDONE)
	{
		if (info->param.num_philo > 0 && info->stuffed_philo == info->param.num_philo)
		{
			pthread_mutex_lock(&(info->philo_mtx));
			printf("\n*** all philos have got enough meals ***\n");
			pthread_mutex_unlock(&(info->philo_mtx));
			info->is_done = DONE;
			return (NULL);
		}		
		philo = &(info->philos[idx]);
		gettimeofday(&now, NULL);
		interval = get_time_interval(now, philo->last_eat);
		if (interval >= philo->info->param.ms_to_die)
		{
			pthread_mutex_lock(&(info->philo_mtx));
			printf("%llums\t%d\tdied\n", interval, philo->name);
			pthread_mutex_unlock(&(info->philo_mtx));
			info->is_done = DONE;
			return (NULL);
		}
		idx++;
		usleep(200);
	}
	return (NULL);
}
