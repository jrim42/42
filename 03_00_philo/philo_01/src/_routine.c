/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _routine.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 21:36:13 by jrim              #+#    #+#             */
/*   Updated: 2022/08/04 12:59:27 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *void_philo);
static void	philo_get_fork(t_philo *philo);
static void	philo_eat(t_philo *philo);
static void	philo_sleep(t_philo *philo);
static void	philo_think(t_philo *philo);

void	*routine(void *void_philo)
{
	t_philo *philo;
	t_info	*info;

	philo = void_philo;
	info = philo->info;
	philo->last_eat = info->birthday;
	while (info->is_done == UNDONE)
	{
		philo_get_fork(philo);
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
		usleep(200);
	}
	return (NULL);
}

static void	philo_get_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_left);
	print_routine(philo, "get the fork on the left side\n");
	pthread_mutex_lock(philo->fork_right);
	print_routine(philo, "get the fork on the right side\n");
}

static void	philo_eat(t_philo *philo)
{
	t_info			*info;
	
	info = philo->info;
	print_routine(philo, "is eating\n");
	usleep(info->param.ms_to_eat * 1000);
	gettimeofday(&philo->last_eat, NULL);
	philo->eat_cnt++;
	if (philo->eat_cnt == info->param.num_eat)
		info->stuffed_philo++;
	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_unlock(philo->fork_left);
}

static void	philo_sleep(t_philo *philo)
{
	print_routine(philo, "needs some sleep...\n");
	usleep(philo->info->param.ms_to_sleep * 1000);
}

static void	philo_think(t_philo *philo)
{
	print_routine(philo, "philo thinks, therefore he is...\n");
}
