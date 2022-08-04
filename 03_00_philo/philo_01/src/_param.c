/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _param.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:55:41 by jrim              #+#    #+#             */
/*   Updated: 2022/08/04 19:33:45 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		init_param(int argc, char **argv, t_param *param);
int		_get_param(int argc, char **argv, t_param *param);
int		philo_atoi(const char *str);
char	*philo_strchr(const char *s, int c);

int	init_param(int argc, char **argv, t_param *param)
{
	if (argc < 5 || argc > 6)
		return (print_error("invalid param num", FAILURE));
	if (_get_param(argc, argv, param) == INVALID)
		return (print_error("invalid param", FAILURE));
	return (SUCCESS);
}

int	_get_param(int argc, char **argv, t_param *param)
{
	param->num_philo = philo_atoi(argv[1]);
	if (param->num_philo <= 0)
		return (INVALID);
	param->ms_to_die = philo_atoi(argv[2]);
	if (param->ms_to_die <= 0)
		return (INVALID);
	param->ms_to_eat = philo_atoi(argv[3]);
	if (param->ms_to_eat <= 0)
		return (INVALID);
	param->ms_to_sleep = philo_atoi(argv[4]);
	if (param->ms_to_sleep <= 0)
		return (INVALID);
	if (argc == 6)
	{
		param->num_eat = philo_atoi(argv[5]);
		if (param->num_eat <= 0)
			return (INVALID);
	}
	else
		param->num_eat = 0;
	return (VALID);
}

int	philo_atoi(const char *str)
{
	unsigned long	num;
	char			*ptr;

	num = 0;
	ptr = (char *)str;
	while (*ptr)
	{
		if (philo_strchr(NUM, *ptr) == 0)
			return (0);
		num += (*ptr) - '0';
		if (*(ptr + 1) && philo_strchr(NUM, *(ptr + 1)))
			num *= 10;
		ptr++;
	}
	if (num > INT_MAX)
		return (0);
	return ((int)num);
}

char	*philo_strchr(const char *s, int c)
{
	int		len;
	char	*ptr;
	int		idx;

	len = 0;
	while (s[len])
		len++;
	len++;
	ptr = (char *)s;
	idx = -1;
	while (++idx < len)
	{
		if (*ptr == (char)c)
			return (ptr);
		ptr++;
	}
	return (0);
}
