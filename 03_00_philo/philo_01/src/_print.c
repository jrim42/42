/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _print.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 17:21:27 by jrim              #+#    #+#             */
/*   Updated: 2022/08/04 12:54:48 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		print_error(char *err_msg, int error);
void		print_routine(t_philo *philo, char *msg);
long long	get_time_interval(struct timeval t1, struct timeval t2);
void		print_param(t_param *param);

int		print_error(char *err_msg, int error)
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

long long	get_time_interval(struct timeval t1, struct timeval t2)
{
	long long		t1_ms;
	long long		t2_ms;
	long long		interval;

	t1_ms = t1.tv_sec * 1000 + t1.tv_usec / 1000;
	t2_ms = t2.tv_sec * 1000 + t2.tv_usec / 1000;
	interval = t1_ms - t2_ms;
	return (interval);
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

// void	print_philo(t_philo *philo)
// {
// 	int			idx;
// 	long long	last_eat;

// 	idx = -1;
// 	while (++idx < philo->info->param.num_philo)
// 	{
// 		last_eat = philo[idx].last_eat.tv_sec * 1000 + philo[idx].last_eat.tv_usec / 1000;
// 		printf("---------------------\n");
// 		printf("   name   :  %d\n", philo[idx].name);
// 		printf("   fork   :  %d and %d\n", philo[idx].fork_left, philo[idx].fork_right);
// 		printf(" birthday :  %lld\n", last_eat);
// 		printf("---------------------\n");
// 	}
// }