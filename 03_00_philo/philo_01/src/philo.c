/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 20:48:40 by jrim              #+#    #+#             */
/*   Updated: 2022/08/04 12:59:24 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		init_info(t_param *param, t_info *info);
int		init_philo(t_philo *philo, t_param *param, t_info *info);
void	create_philo(t_info *info, t_philo *philo);
void	bye_philo(t_info *info);

int	main(int argc, char **argv)
{
	t_info	info;

	if (init_param(argc, argv, &(info.param)) == FAILURE)
		return (RETURN_ERROR);
	if (init_info(&(info.param), &info) == FAILURE)
		return (RETURN_ERROR);
	if (init_philo(info.philos, &(info.param), &info) == FAILURE)
		return (RETURN_ERROR);
	create_philo(&info, info.philos);
	// 모든 thread가 종료될 때까지 대기한다.
	bye_philo(&info);
	return (0);
}

int		init_info(t_param *param, t_info *info)
{
	// fork mutex and array allocation
	info->fork_mtx = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * param->num_philo);
	if (info->fork_mtx == NULL)
		return (print_error("cannot allocate memory", FAILURE));
	// details
	info->is_done = UNDONE;
	info->stuffed_philo = 0;
	pthread_mutex_init(&(info->philo_mtx), NULL);
	return (SUCCESS);
}

int	init_philo(t_philo *philos, t_param *param, t_info *info)
{
	int				idx;

	philos = (t_philo *)malloc(sizeof(t_philo) * param->num_philo);
	if (philos == NULL)
		return (print_error("cannot allocate memory", FAILURE));
	idx = -1;
	while (++idx < param->num_philo)
	{
		philos[idx].name = idx;
		philos[idx].eat_cnt = 0;
		philos[idx].info = info;
		if (idx == 0)
			philos[idx].fork_left = &(info->fork_mtx[param->num_philo - 1]);
		else
			philos[idx].fork_left = &(info->fork_mtx[idx - 1]);
		philos[idx].fork_right = &(info->fork_mtx[idx]);
		pthread_mutex_init(&info->fork_mtx[idx], NULL);
	}
	return (SUCCESS);
}

void	create_philo(t_info *info, t_philo *philos)
{
	int			idx;
	pthread_t	thread;

	gettimeofday(&(info->birthday), NULL);
	idx = 1;
	while (idx < info->param.num_philo)
	{
		printf("in\n");
		philos[idx].last_eat = info->birthday;
		printf("in\n");
		pthread_create(&thread, NULL, routine, (void *)&philos[idx]);
		pthread_detach(thread);
		usleep(info->param.ms_to_eat * 200);
		idx += 2;
	}
	idx = 0;
	while (idx < info->param.num_philo)
	{
		philos[idx].last_eat = info->birthday;
		pthread_create(&thread, NULL, routine, (void *)&philos[idx]);
		pthread_detach(thread);
		idx += 2;
	}
	pthread_create(&thread, NULL, eggshell, (void *)info);
}

void	bye_philo(t_info *info)
{
	int			idx;
	
	idx = -1;
	while (++idx > info->param.num_philo)
		pthread_mutex_destroy(&info->fork_mtx[idx]);	
	pthread_mutex_destroy(&info->philo_mtx);			
	free(info->philos);
	free(info->fork_mtx);
}