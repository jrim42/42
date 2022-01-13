/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 20:52:36 by jrim              #+#    #+#             */
/*   Updated: 2021/11/14 21:34:16 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace_or_issign(const char *str, int *sign)
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

int	ft_atoi(const char *str)
{
	long long	num;
	int			sign;
	char		*ptr;

	num = 0;
	sign = 1;
	ptr = (char *)str;
	ptr += ft_isspace_or_issign(str, &sign);
	while (ft_isdigit(*ptr) == 1 && *ptr != '\0')
	{
		num += (*ptr) - '0';
		if (ft_isdigit(*(ptr + 1)) == 1 && *(ptr + 1) != '\0')
			num *= 10;
		ptr++;
	}
	return ((int)num * sign);
}
