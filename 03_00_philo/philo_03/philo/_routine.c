/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _routine.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 21:36:13 by jrim              #+#    #+#             */
/*   Updated: 2022/09/02 20:50:18 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void		*routine(void *void_philo);
static int	philo_get_fork(t_info *info, t_philo *philo);
static int	philo_eat(t_info *info, t_philo *philo);
static int	philo_sleep(t_info *info, t_philo *philo);
static int	philo_think(t_info *info, t_philo *philo);

void	*routine(void *void_philo)
{
	t_philo	*philo;
	t_info	*info;

	philo = (t_philo *)void_philo;
	info = philo->info;
	if (philo->name % 2 == 0)
		usleep(100);
	gettimeofday(&(philo->last_eat), NULL);
	while (philo->is_dead == ALIVE)
	{
		if (philo_get_fork(info, philo) == DEAD)
			break ;
		if (philo_eat(info, philo) == DEAD)
			break ;
		if (philo_sleep(info, philo) == DEAD)
			break ;
		if (philo_think(info, philo) == DEAD)
			break ;
		usleep(100);
	}
	return (NULL);
}

static int	philo_get_fork(t_info *info, t_philo *philo)
{
	if (is_philo_dead(info, philo) == DEAD)
		return (DEAD);
	pthread_mutex_lock(philo->fork_left);
	print_routine(philo, "has taken a fork");
	if (info->param.n_philo == 1)
	{
		usleep(info->param.ms_die * 1001);
		pthread_mutex_unlock(philo->fork_left);
		return (is_philo_dead(info, philo));
	}
	pthread_mutex_lock(philo->fork_right);
	print_routine(philo, "has taken a fork");
	if (is_philo_dead(info, philo) == DEAD)
	{
		pthread_mutex_unlock(philo->fork_left);
		pthread_mutex_unlock(philo->fork_right);
		return (DEAD);
	}
	return (ALIVE);
}

static int	philo_eat(t_info *info, t_philo *philo)
{
	struct timeval	start;
	struct timeval	now;

	print_routine(philo, "is eating");
	pthread_mutex_lock(&(philo->eat_mtx));
	gettimeofday(&philo->last_eat, NULL);
	philo->eat_cnt++;
	pthread_mutex_unlock(&(philo->eat_mtx));
	gettimeofday(&start, NULL);
	while (1)
	{
		gettimeofday(&now, NULL);
		if (get_time_interval(now, start) >= \
			(long long)info->param.ms_eat)
			break ;
		usleep (100);
	}
	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_unlock(philo->fork_right);
	return (ALIVE);
}

static int	philo_sleep(t_info *info, t_philo *philo)
{
	struct timeval	start;
	struct timeval	now;

	if (is_philo_dead(info, philo) == DEAD)
		return (DEAD);
	print_routine(philo, "is sleeping");
	gettimeofday(&start, NULL);
	while (1)
	{
		gettimeofday(&now, NULL);
		if (get_time_interval(now, start) >= \
			(long long)info->param.ms_sleep)
			break ;
		usleep (100);
	}
	return (ALIVE);
}

static int	philo_think(t_info *info, t_philo *philo)
{
	if (is_philo_dead(info, philo) == DEAD)
		return (DEAD);
	print_routine(philo, "is thinking");
	return (ALIVE);
}
