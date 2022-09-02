/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _utils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 14:12:06 by jrim              #+#    #+#             */
/*   Updated: 2022/09/02 20:23:19 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time_interval(struct timeval t1, struct timeval t2);
int			print_error(char *err_msg, int error);
void		print_routine(t_philo *philo, char *msg);
void		print_dead(t_philo *philo, t_info *info);

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
	t_info			*info;
	long long		interval;
	struct timeval	now;

	info = philo->info;
	pthread_mutex_lock(&(info->main_mtx));
	if (philo->is_dead == DEAD || info->is_done == DONE)
	{
		pthread_mutex_unlock(&(info->main_mtx));
		return ;
	}
	pthread_mutex_unlock(&(info->main_mtx));
	pthread_mutex_lock(&(info->msg_mtx));
	gettimeofday(&now, NULL);
	interval = get_time_interval(now, info->birthday);
	printf("%llums\t%d\t%s\n", interval, philo->name, msg);
	pthread_mutex_unlock(&(info->msg_mtx));
}

void	print_dead(t_philo *philo, t_info *info)
{
	struct timeval	now;
	long long		interval;

	pthread_mutex_lock(&(info->main_mtx));
	philo->is_dead = DEAD;
	info->is_done = DONE;
	pthread_mutex_unlock(&(info->main_mtx));
	pthread_mutex_lock(&(info->msg_mtx));
	gettimeofday(&now, NULL);
	interval = get_time_interval(now, info->birthday);
	printf("%llums\t%d\tdied\n", interval, philo->name);
	pthread_mutex_unlock(&(info->msg_mtx));
}
