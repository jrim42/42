/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 20:48:40 by jrim              #+#    #+#             */
/*   Updated: 2022/08/04 02:32:41 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		init_info(t_param *param, t_info *info);
int		init_philo(t_philo *philo, t_param *param, t_info *info);
static void	create_philo(t_info *info, t_philo *philo);
static void	bye_philo(t_info *info, t_philo *philo);

int	main(int argc, char **argv)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	info->param = (t_param *)malloc(1 * sizeof(t_param));
	if (info == NULL || info->param == NULL)
		print_error("cannot allocate memory", 12);
		
	if (parse_param(argc, argv, info->param) == FAILURE)
		return (1);
	if (init_info(info->param, info) == FAILURE)
		return (1);
		
	info->philo = (t_philo *)malloc(sizeof(t_philo) * info->param->num_philo);
	if (info->philo == NULL)
		print_error("cannot allocate memory", 12);
	if (init_philo(info->philo, info->param, info) == FAILURE)
		return (1);
		
	create_philo(info, info->philo);
	// 모든 thread가 종료될 때까지 대기한다.
	bye_philo(info, info->philo);
	// free(info);
	return (0);
}

int		init_info(t_param *param, t_info *info)
{
	int idx;
	
	pthread_mutex_init(info->philo_mtx, NULL);
	// fork mutex and array allocation
	info->philo_mtx = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	info->fork_mtx = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * param->num_philo);
	info->fork_arr = (int *)malloc(sizeof(int) * param->num_philo);
	if (info->philo_mtx == NULL || info->fork_mtx == NULL || info->fork_arr == NULL)
		print_error("cannot allocate memory", 12);
	idx = -1;
	while (++idx < param->num_philo)
	{
		// fork mutex init
		pthread_mutex_init(&info->fork_mtx[idx], NULL);
		info->fork_arr[idx] = UNOCCUPIED;
	}
	// details
	info->is_done = UNDONE;
	info->stuffed_philo = 0;	// 이게 맞아?
	return (SUCCESS);
}

int	init_philo(t_philo *philo, t_param *param, t_info *info)
{
	int				idx;

	// philo = (t_philo *)malloc(sizeof(t_philo) * param->num_philo);
	// if (philo == NULL)
	// 	print_error("cannot allocate memory", 12);
	idx = -1;
	while (++idx < param->num_philo)
	{
		philo[idx].name = idx;
		pthread_mutex_init(&(philo[idx].checker), NULL);
		if (idx == 0)
			philo[idx].fork_left = param->num_philo - 1;
		else
			philo[idx].fork_left = idx - 1;
		philo[idx].fork_right = idx;
		philo[idx].eat_cnt = 0;
		philo->info = info;
	}
	return (SUCCESS);
}

static void	create_philo(t_info *info, t_philo *philo)
{
	int			idx;
	pthread_t	thread;

	gettimeofday(&info->birthday, NULL);
	idx = -1;
	while (++idx < info->param->num_philo)
	{
		philo[idx].last_eat = info->birthday;
		pthread_create(philo[idx].thread, NULL, routine, (void *)&philo[idx]);
		pthread_create(&thread, NULL, eggshell_1, (void *)&philo[idx]);
		pthread_detach(thread);
	}
	if (info->param->num_eat > 0)
	{
		pthread_create(&thread, NULL, eggshell_2, philo->info);
		pthread_detach(thread);
	}
}

static void	bye_philo(t_info *info, t_philo *philo)
{
	int			idx;
	
	idx = -1;
	while (++idx < info->param->num_philo)
	{
		pthread_join(*(philo[idx].thread), NULL);
		pthread_mutex_destroy(&(philo[idx].checker));
	}
	free(info->philo);
	while (idx-- > 0)
		pthread_mutex_destroy(&info->fork_mtx[idx]);		
	free(info->fork_mtx);
}