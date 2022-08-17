/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _routine.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 21:36:13 by jrim              #+#    #+#             */
/*   Updated: 2022/08/17 22:49:11 by jrim             ###   ########.fr       */
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
	if (philo->name % 2 == 0)
		usleep(100);
	gettimeofday(&(philo->last_eat), NULL);
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
	if (philo->info->is_done == DONE)
		return ;
	pthread_mutex_lock(philo->fork_left);
	pthread_mutex_lock(philo->fork_right);
	if (philo->info->is_done == DONE)
	{
		pthread_mutex_unlock(philo->fork_left);
		pthread_mutex_unlock(philo->fork_right);
		return ;
	}
	print_routine(philo, "has taken a fork");
}

static void	philo_eat(t_philo *philo)
{
	t_info			*info;
	struct timeval	start;
	struct timeval	now;

	info = philo->info;
	if (info->is_done == DONE)
	{
		pthread_mutex_unlock(philo->fork_left);
		pthread_mutex_unlock(philo->fork_right);
		return ;
	}
	print_routine(philo, "is eating");
	gettimeofday(&start, NULL);
	while (1)
	{
		gettimeofday(&now, NULL);
		if (get_time_interval(now, start) >= \
			(long long)info->param.ms_eat)
			break ;
		usleep (10);
	}
	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_unlock(philo->fork_right);
	gettimeofday(&philo->last_eat, NULL);
	philo->eat_cnt++;
}

static void	philo_sleep(t_philo *philo)
{
	t_info			*info;
	struct timeval	start;
	struct timeval	now;

	info = philo->info;
	if (info->is_done == DONE)
		return ;
	print_routine(philo, "is sleeping");
	gettimeofday(&start, NULL);
	while (1)
	{
		gettimeofday(&now, NULL);
		if (get_time_interval(now, start) >= \
			(long long)info->param.ms_sleep)
			break ;
		usleep (10);
	}
}

static void	philo_think(t_philo *philo)
{
	if (philo->info->is_done == DONE)
		return ;
	print_routine(philo, "is thinking");
}
