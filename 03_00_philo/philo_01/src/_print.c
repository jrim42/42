/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _print.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 17:21:27 by jrim              #+#    #+#             */
/*   Updated: 2022/08/04 13:35:09 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int			print_error(char *err_msg, int error);
void		print_routine(t_philo *philo, char *msg);
void		print_param(t_param *param);

int	print_error(char *err_msg, int error)
{
	printf("error: %s\n", err_msg);
	return (error);
}

void	print_routine(t_philo *philo, char *msg)
{
	long long		interval;
	struct timeval	now;
	int				philo_name;

	if (philo->info->is_done == DONE)
		return ;
	philo_name = philo->name + 1;
	pthread_mutex_lock(&(philo->info->philo_mtx));
	gettimeofday(&now, NULL);
	interval = get_time_interval(now, philo->info->birthday);
	if (philo->info->is_done == UNDONE)
		printf("%lld\t%d\t%s\n", interval, philo_name, msg);
	pthread_mutex_unlock(&(philo->info->philo_mtx));
}

void	print_param(t_param *param)
{
	printf("---------------------\n");
	printf("  philo  :  %d\n", param->num_philo);
	printf("   die   :  %d\n", param->ms_to_die);
	printf("   eat   :  %d\n", param->ms_to_eat);
	printf("  sleep  :  %d\n", param->ms_to_sleep);
	if (param->num_eat != -1)
		printf(" num eat :  %d\n", param->num_eat);
	printf("---------------------\n");
}
