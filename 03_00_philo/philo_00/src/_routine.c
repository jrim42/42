/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _routine.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 21:36:13 by jrim              #+#    #+#             */
/*   Updated: 2022/08/01 19:08:39 by jrim             ###   ########.fr       */
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
	while (1)
	{
		philo_get_fork(philo);
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
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
	print_routine(philo, "now he's got two forks...\n");
	
}

void	philo_sleep(t_philo *philo)
{
	print_routine(philo, "needs some sleep...\n");
}

void	philo_think(t_philo *philo)
{
	print_routine(philo, "philo thinks, therefore he is...\n");
}
