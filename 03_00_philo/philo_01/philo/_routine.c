/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _routine.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 21:36:13 by jrim              #+#    #+#             */
/*   Updated: 2022/08/05 16:25:24 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void		*routine(void *void_philo);
static void	philo_get_fork(t_philo *philo);
static void	philo_eat(t_philo *philo);
static void	philo_sleep(t_philo *philo);
static void	philo_think(t_philo *philo);

void	*routine(void *void_philo)
{
	t_philo	*philo;
	t_info	*info;

	philo = (t_philo *)void_philo;
	info = philo->info;
	gettimeofday(&(philo->last_eat), NULL);
	if (philo->name % 2 == 0)
		usleep(info->param.t_eat * 10);
	while (info->is_done == UNDONE)
	{
		philo_get_fork(philo);
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
		usleep(100);
	}
	return (NULL);
}

static void	philo_get_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_left);
	pthread_mutex_lock(philo->fork_right);
	print_routine(philo, "has taken a fork");
}

static void	philo_eat(t_philo *philo)
{
	t_info			*info;
	struct timeval	now;

	info = philo->info;
	print_routine(philo, "is eating");
	gettimeofday(&philo->last_eat, NULL);
	while (1)
	{
		gettimeofday(&now, NULL);
		if (get_time_interval(now, philo->last_eat) >= \
			(long long)info->param.t_eat)
			break ;
		usleep (10);
	}
	gettimeofday(&philo->last_eat, NULL);
	philo->eat_cnt++;
	if (philo->eat_cnt == info->param.n_eat)
		info->stuffed_philo++;
	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_unlock(philo->fork_right);
}

static void	philo_sleep(t_philo *philo)
{
	t_info			*info;
	struct timeval	now;
	struct timeval	sleep;

	info = philo->info;
	print_routine(philo, "is sleeping");
	gettimeofday(&sleep, NULL);
	while (1)
	{
		gettimeofday(&now, NULL);
		if (get_time_interval(now, sleep) >= \
			(long long)info->param.t_sleep)
			break ;
		usleep (10);
	}
}

static void	philo_think(t_philo *philo)
{
	print_routine(philo, "is thinking");
}
