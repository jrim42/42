/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _param.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:55:41 by jrim              #+#    #+#             */
/*   Updated: 2022/08/03 22:49:41 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		parse_param(int argc, char **argv, t_param *param);
int		_check_arg(int argc, char **argv);
void	_get_param(int argc, char **argv, t_param *param);
int 	_check_param(int argc, t_param *param);

int	parse_param(int argc, char **argv, t_param *param)
{
	// param = (t_param *)malloc(1 * sizeof(t_param));
	// if (!param)
	// 	print_error("cannot allocate memory", 12);
	if (argc < 5 || argc > 6)
		print_error("invalid param number", 1);
	if (_check_arg(argc, argv) == INVALID)
		print_error("invalid character in params", 1);
	_get_param(argc, argv, param);
	if (_check_param(argc, param) == INVALID)
		print_error("invalid params", 1);
	return (SUCCESS);
}

int _check_arg(int argc, char **argv)
{
	int	idx1;
	int	idx2;

	idx1 = 0;
	while (++idx1 < argc)
	{
		idx2 = -1;
		while (argv[idx1][++idx2])
		{
			// while (ft_strchr(WH_SP, argv[idx1][idx2]))
			//     idx2++;
			if (ft_strchr(NUM, argv[idx1][idx2]) == 0)
				return (INVALID);
		}
	}
	return (VALID);
}

void	_get_param(int argc, char **argv, t_param *param)
{
	param->num_philo = philo_atoi(argv[1]);
	param->ms_to_die = philo_atoi(argv[2]);
	param->ms_to_eat = philo_atoi(argv[3]);
	param->ms_to_sleep = philo_atoi(argv[4]);
	if (argc == 6)
		param->num_eat = philo_atoi(argv[5]);
	else
		param->num_eat = -1;
}

int 	_check_param(int argc, t_param *param)
{
	if (param->num_philo <= 0)
		return (INVALID);
	else if (param->ms_to_die < 0)
		return (INVALID);
	else if (param->ms_to_eat < 0)
		return (INVALID);
	else if (param->ms_to_sleep < 0)
		return (INVALID);
	else if (argc == 6 && param->num_eat < 0)
		return (INVALID);
	return (VALID);
}