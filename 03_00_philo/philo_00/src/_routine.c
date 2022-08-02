/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _routine.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 21:36:13 by jrim              #+#    #+#             */
/*   Updated: 2022/08/02 17:33:17 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(t_philo *philo);
void	philo_get_fork(t_philo *philo);
void	philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);

void	*routine(t_philo *philo)
{
	if (philo->name % 2 == 0)
		usleep(philo->info->param->ms_to_eat * 1000);
	while (1)
	{
		philo_get_fork(philo);
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

void	philo_get_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_left);
	print_routine(philo, "get the fork on the left side!\n");
	pthread_mutex_lock(philo->fork_right);
	print_routine(philo, "get the fork on the right side!\n");
}

void	philo_eat(t_philo *philo)
{
	long long	interval;
	t_info		*info;

	info = philo->info;
	pthread_mutex_lock(&philo->checker);
	gettimeofday(&philo->last_eat, NULL);
	interval = get_time_interval(philo->last_eat, info->birthday);
	pthread_mutex_lock(info->is_done);
	if (info->flag == UNDONE)
		printf("%lld\t%d\t is eating\n", interval, philo->name + 1);
	info->hungry_philo--;
	// 
	pthread_mutex_unlock(info->is_done);
	usleep(info->param->ms_to_eat * 1000);
	pthread_mutex_unlock(&philo->fork_left);
	pthread_mutex_unlock(&philo->fork_right);
	pthread_mutex_unlock(&philo->checker);
}

void	philo_sleep(t_philo *philo)
{
	print_routine(philo, "needs some sleep...\n");
	usleep(philo->info->param->ms_to_sleep * 1000);

}

void	philo_think(t_philo *philo)
{
	print_routine(philo, "philo thinks, therefore he is...\n");
}
