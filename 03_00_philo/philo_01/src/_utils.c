/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _utils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 14:12:06 by jrim              #+#    #+#             */
/*   Updated: 2022/08/04 12:55:43 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		philo_atoi(const char *str);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);

int	philo_atoi(const char *str)
{
	unsigned long	num;
	int				sign;
	char			*ptr;

	num = 0;
	sign = 1;
	ptr = (char *)str;
	while (*ptr && ft_strchr(WH_SP, *ptr))
		ptr++;
	if (*ptr == '-')
	{
		sign = -1;
		ptr++;
	}
	while (*ptr && ft_strchr(NUM, *ptr))
	{
		num += (*ptr) - '0';
		if (*(ptr + 1) && ft_strchr(NUM, *(ptr + 1)))
			num *= 10;
		ptr++;
	}
	if (num > LONG_MAX)
		print_error("out of bounds", 1);
	return ((int)num * sign);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	idx;
	size_t	s_len;
	char	*ptr;

	idx = 0;
	s_len = ft_strlen(s) + 1;
	ptr = (char *)s;
	while (idx < s_len)
	{
		if (*ptr == (char)c)
			return (ptr);
		idx++;
		ptr++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}
