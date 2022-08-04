/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _routine.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 21:36:13 by jrim              #+#    #+#             */
/*   Updated: 2022/08/04 19:57:16 by jrim             ###   ########.fr       */
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
	philo->last_eat = info->birthday;
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
	if (pthread_mutex_lock(philo->fork_left) == 0)
		print_routine(philo, "has taken a fork (L)");
	else 
		pthread_mutex_unlock(&(philo->info->philo_mtx));
	if (pthread_mutex_lock(philo->fork_right) == 0)
		print_routine(philo, "has taken a fork (R)");
	else 
		pthread_mutex_unlock(&(philo->info->philo_mtx));
}

static void	philo_eat(t_philo *philo)
{
	t_info			*info;

	info = philo->info;
	print_routine(philo, "is eating");
	gettimeofday(&philo->last_eat, NULL);
	usleep(info->param.ms_to_eat * 100);
	philo->eat_cnt++;
	if (philo->eat_cnt == info->param.num_eat)
		info->stuffed_philo++;
	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_unlock(philo->fork_left);
}

static void	philo_sleep(t_philo *philo)
{
	print_routine(philo, "is sleeping");
	usleep(philo->info->param.ms_to_sleep * 100);
}

static void	philo_think(t_philo *philo)
{
	print_routine(philo, "is thinking");
}
