/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _eggshell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 22:25:00 by jrim              #+#    #+#             */
/*   Updated: 2022/08/02 17:30:15 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*eggshell_1(t_philo *philo)
{
	struct timeval	time_info;
	long long		interval;

	while (!philo->info->flag)
	{
		pthread_mutex_lock(&philo->checker);
		pthread_mutex_lock(&philo->info->is_done);
		gettimeofday(&time_info, NULL);
		interval = convert_to_ms(time_info, philo->last_eat);
		gettimeofday(&time_info, NULL);
		if (interval >= philo->info->param->ms_to_die && \
			philo->info->flag == UNDONE)
		{
			printf("%lld\t%d\t died\n", \
				convert_to_ms(time_info, philo->last_eat), philo->name + 1);
			philo->info->flag = DONE;
		}
		pthread_mutex_unlock(&philo->info->is_done);
		pthread_mutex_unlock(&philo->checker);
	}
	return (NULL);
}

void	*eggshell_2(t_info	*info)
{
	while (info->flag == UNDONE)
	{
		pthread_mutex_lock(&info->is_done);
		if (info->hungry_philo == 0)
			info->flag = DONE;
		pthread_mutex_unlock(&info->is_done);
	}
	return (NULL);
}