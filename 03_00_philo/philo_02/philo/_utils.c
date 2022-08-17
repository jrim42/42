/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _utils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 14:12:06 by jrim              #+#    #+#             */
/*   Updated: 2022/08/17 23:54:37 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time_interval(struct timeval t1, struct timeval t2);
int			print_error(char *err_msg, int error);
void		print_routine(t_philo *philo, char *msg);

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

int	print_error(char *err_msg, int error)
{
	printf("error: %s\n", err_msg);
	return (error);
}

void	print_routine(t_philo *philo, char *msg)
{
	long long		interval;
	struct timeval	now;

	if (philo->info->is_done == DONE)
		return ;
	pthread_mutex_lock(&(philo->info->msg_mtx));
	gettimeofday(&now, NULL);
	interval = get_time_interval(now, philo->info->birthday);
	// printf("%llu\t%d\t%s\n", interval, philo->name, msg);
	printf("%llums\t%d\t%s\n", interval, philo->name, msg);
	pthread_mutex_unlock(&(philo->info->msg_mtx));
}
