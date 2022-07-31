/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _routine.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 21:36:13 by jrim              #+#    #+#             */
/*   Updated: 2022/07/31 21:51:01 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	routine(t_philo *philo);
void	philo_get_fork(t_philo *philo);
void	philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);

void	routine(t_philo *philo)
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
	pthread_mutex_lock(philo->fork_r);
	//
	pthread_mutex_lock(philo->fork_l);
	//
}

void	philo_eat(t_philo *philo)
{
	if (philo)
		printf("philo needs two forks...\n");
}

void	philo_sleep(t_philo *philo)
{
	if (philo)
		printf("philo needs some sleep...\n");	
}

void	philo_think(t_philo *philo)
{
	if (philo)
		printf("philo thinks, therefore he is...\n");	
}
