/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _routine.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 21:36:13 by jrim              #+#    #+#             */
/*   Updated: 2022/08/03 23:31:58 by jrim             ###   ########.fr       */
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

	philo = void_philo;
	if (philo->name % 2 != 0)
		usleep(philo->info->param->ms_to_eat * 1000);
	while (philo->info->is_done == UNDONE)
	{
		philo_get_fork(philo);
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

static void	philo_get_fork(t_philo *philo)
{
	pthread_mutex_t *fork;

	fork = philo->info->fork_mtx;
	pthread_mutex_lock(&fork[philo->fork_left]);
	philo->info->fork_arr[philo->fork_left] = OCCUPIED;
	print_routine(philo, "get the fork on the left side\n");
	pthread_mutex_lock(&fork[philo->fork_right]);
	philo->info->fork_arr[philo->fork_right] = OCCUPIED;
	print_routine(philo, "get the fork on the right side\n");
}

static void	philo_eat(t_philo *philo)
{
	t_info			*info;
	pthread_mutex_t *fork;
	
	info = philo->info;
	fork = philo->info->fork_mtx;
	print_routine(philo, "is eating\n");
	usleep(info->param->ms_to_eat * 1000);
	gettimeofday(&philo->last_eat, NULL);	// 마지막 식사 시간 갱신
	philo->eat_cnt++;
	if (philo->eat_cnt == info->param->num_eat)
		info->hungry_philo--;
	// 먹은 애들 체크해줘야함
	// 먹고 나면 포크를 내려놓습니다...
	pthread_mutex_unlock(&fork[philo->fork_left]);
	philo->info->fork_arr[philo->fork_left] = UNOCCUPIED;
	pthread_mutex_unlock(&fork[philo->fork_right]);
	philo->info->fork_arr[philo->fork_left] = UNOCCUPIED;
}

static void	philo_sleep(t_philo *philo)
{
	print_routine(philo, "needs some sleep...\n");
	usleep(philo->info->param->ms_to_sleep * 1000);
}

static void	philo_think(t_philo *philo)
{
	print_routine(philo, "philo thinks, therefore he is...\n");
}
