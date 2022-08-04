/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _eggshell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 22:25:00 by jrim              #+#    #+#             */
/*   Updated: 2022/08/04 12:54:32 by jrim             ###   ########.fr       */
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
		if (info->stuffed_philo == info->param.num_philo)
		{
			pthread_mutex_lock(&(info->philo_mtx));
			printf("*** all philos have got enough meals ***\n");
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
			printf("%lld\t%d\t died\n", interval, philo->name + 1);
			pthread_mutex_unlock(&(info->philo_mtx));
			info->is_done = DONE;
			return (NULL);
		}
		idx++;
		usleep(200);
	}
	return (NULL);
}

// void	*eggshell_1(void *void_philo)
// {
// 	t_philo			*philo;
// 	struct timeval	time_info;
// 	long long		interval;

// 	philo = void_philo;
// 	while (!philo->info->is_done)
// 	{
// 		// pthread_mutex_lock(philo->checker);
// 		pthread_mutex_lock(philo->info->philo_mtx);
// 		gettimeofday(&time_info, NULL);
// 		interval = get_time_interval(time_info, philo->last_eat);
// 		gettimeofday(&time_info, NULL);
// 		if (interval >= philo->info->param->ms_to_die && \
// 			philo->info->is_done == UNDONE)
// 		{
// 			printf("%lld\t%d\t died\n", \
// 				get_time_interval(time_info, philo->last_eat), philo->name + 1);
// 			philo->info->is_done = DONE;
// 		}
// 		pthread_mutex_unlock(philo->info->philo_mtx);
// 		// pthread_mutex_unlock(philo->checker);
// 	}
// 	return (NULL);
// }

// void	*eggshell_2(void *void_info)
// {
// 	t_info	*info;

// 	info = void_info;
// 	while (info->is_done == UNDONE)
// 	{
// 		pthread_mutex_lock(info->philo_mtx);
// 		if (info->hungry_philo == 0)
// 			info->is_done = DONE;
// 		pthread_mutex_unlock(info->philo_mtx);
// 	}
// 	return (NULL);
// }