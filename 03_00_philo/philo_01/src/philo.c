/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 20:48:40 by jrim              #+#    #+#             */
/*   Updated: 2022/08/05 13:23:11 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		init_info(t_param *param, t_info *info);
int		init_philo(t_philo *philo, t_param *param, t_info *info);
int		create_philo(t_info *info);
void	bye_philo(t_info *info);

int	main(int argc, char **argv)
{
	t_info		info;

	if (init_param(argc, argv, &(info.param)) == FAILURE)
		return (RETURN_ERROR);
	if (init_info(&(info.param), &info) == FAILURE)
		return (RETURN_ERROR);
	if (init_philo(info.philos, &(info.param), &info) == FAILURE)
		return (RETURN_ERROR);
	if (create_philo(&info) == FAILURE)
		return (print_error("philo error", RETURN_ERROR));
	if (eggshell(&info) == DONE)
		bye_philo(&info);
	return (0);
}

int	init_info(t_param *param, t_info *info)
{
	info->is_done = UNDONE;
	info->stuffed_philo = 0;
	info->fork_mtx = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * param->num_philo);
	if (info->fork_mtx == NULL)
		return (print_error("cannot allocate memory", FAILURE));
	info->philos = (t_philo *)malloc(sizeof(t_philo) * info->param.num_philo);
	if (info->philos == NULL)
	{
		free(info->fork_mtx);
		return (print_error("cannot allocate memory", FAILURE));
	}
	pthread_mutex_init(&(info->print_mtx), NULL);
	pthread_mutex_init(&(info->philo_mtx), NULL);
	// why?
	pthread_mutex_lock(&(info->philo_mtx));
	return (SUCCESS);
}

int	init_philo(t_philo *philos, t_param *param, t_info *info)
{
	int				idx;

	idx = -1;
	while (++idx < param->num_philo)
	{
		philos[idx].name = idx + 1;
		philos[idx].eat_cnt = 0;
		philos[idx].info = info;
		if (idx == param->num_philo - 1)
			philos[idx].fork_left = &(info->fork_mtx[0]);
		else
			philos[idx].fork_left = &(info->fork_mtx[idx + 1]);
		philos[idx].fork_right = &(info->fork_mtx[idx]);
		pthread_mutex_init(&info->fork_mtx[idx], NULL);
	}
	return (SUCCESS);
}

int	create_philo(t_info *info)
{
	int			idx;
	t_philo		philo;

	gettimeofday(&(info->birthday), NULL);
	idx = 0;
	while (idx < info->param.num_philo)
	{
		philo = info->philos[idx];
		if (pthread_create(&(philo.tid), NULL, routine, (void *)&philo))
			return (FAILURE);
		usleep(100);
		idx++;
	}
	return (SUCCESS);
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
