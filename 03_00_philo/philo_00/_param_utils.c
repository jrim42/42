/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _utils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:53:19 by jrim              #+#    #+#             */
/*   Updated: 2022/05/18 17:19:39 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	    ft_atoi(const char *str);
int	    space_or_sign(const char *str, int *sign);
char	*ft_strchr(const char *s, int c);

int	ft_atoi(const char *str)
{
	unsigned long	num;
	int				sign;
	char			*ptr;

	num = 0;
	sign = 1;
	ptr = (char *)str;
	ptr += space_or_sign(str, &sign);
	while (ft_isdigit(*ptr) == 1 && *ptr != '\0')
	{
		num += (*ptr) - '0';
		if (ft_isdigit(*(ptr + 1)) == 1 && *(ptr + 1) != '\0')
			num *= 10;
		ptr++;
	}
	if (num > LONG_MAX)
	{
		if (sign == 1)
			return (-1);
		else
			return (0);
	}
	return ((int)num * sign);
}

int	space_or_sign(const char *str, int *sign)
{
	int	idx;

	idx = 0;
	while (str[idx] == ' ' || str[idx] == '\f' || str[idx] == '\n'
		|| str[idx] == '\r' || str[idx] == '\t' || str[idx] == '\v')
		idx++;
	if (str[idx] == '+' || str[idx] == '-')
	{
		if (str[idx] == '-')
			(*sign) *= (-1);
		idx++;
	}
	return (idx);
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
