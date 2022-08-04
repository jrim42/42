/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _utils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 14:12:06 by jrim              #+#    #+#             */
/*   Updated: 2022/08/04 13:30:27 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time_interval(struct timeval t1, struct timeval t2);
int			philo_atoi(const char *str);
char		*philo_strchr(const char *s, int c);

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

int	philo_atoi(const char *str)
{
	unsigned long	num;
	int				sign;
	char			*ptr;

	num = 0;
	sign = 1;
	ptr = (char *)str;
	while (*ptr && philo_strchr(WH_SP, *ptr))
		ptr++;
	if (*ptr == '-')
	{
		sign = -1;
		ptr++;
	}
	while (*ptr && philo_strchr(NUM, *ptr))
	{
		num += (*ptr) - '0';
		if (*(ptr + 1) && philo_strchr(NUM, *(ptr + 1)))
			num *= 10;
		ptr++;
	}
	if (num > LONG_MAX)
		print_error("out of bounds", 1);
	return ((int)num * sign);
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
