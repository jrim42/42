/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:49:24 by heha              #+#    #+#             */
/*   Updated: 2022/09/19 16:46:21 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	ft_get_mantissa(const char **s)
{
	double	n;

	n = 0.0;
	while (**s && ft_isdigit(**s))
	{
		n = (**s - '0') + n * 10.0;
		(*s)++;
	}
	return (n);
}

static double	ft_get_exponent(const char **s)
{
	double	n;
	double	tmp;

	(*s)++;
	n = 0.0;
	tmp = 0.1;
	while (**s && ft_isdigit(**s))
	{
		n = n + (**s - '0') * tmp;
		tmp *= 0.1;
		(*s)++;
	}
	return (n);
}

static char	*ft_endptr_update(const char *str, \
		const char *cp1, const char *cp2, double *sign)
{
	if ((cp1 == cp2) || (cp2 - cp1 == 1 && *cp1 == '.'))
	{
		*sign = 0.0;
		return ((char *)str);
	}
	else
		return ((char *)cp2);
}

double	ft_strtod(const char *str, char **endptr)
{
	double		sign;
	double		mantissa;
	double		exponent;
	const char	*cp1 = str;
	const char	*cp2 = str;

	sign = 1.0;
	mantissa = 0.0;
	exponent = 0.0;
	while (*cp1 && ft_isspace(*cp1))
		cp1++;
	if (*cp1 == '-' || *cp1 == '+')
		if (*cp1++ == '-')
			sign = -1.0;
	cp2 = cp1;
	mantissa = ft_get_mantissa(&cp2);
	if (*cp2 == '.')
		exponent = ft_get_exponent(&cp2);
	if (endptr)
		*endptr = ft_endptr_update(str, cp1, cp2, &sign);
	return (sign * (mantissa + exponent));
}
