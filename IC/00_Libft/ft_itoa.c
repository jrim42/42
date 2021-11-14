/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 20:59:16 by jrim              #+#    #+#             */
/*   Updated: 2021/11/14 21:05:45 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	numlen(int n)
{
	int	len;

	if (n < 0)
	{
		len = 1;
		n *= -1;
	}
	else
		len = 0;
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		idx;

	if (n == -2147483648)
		return ("-2147483648");
	else if (n == 0)
		return ("0");
	else
	{
		str = (char *)malloc((numlen(n) + 1) * sizeof(char));
		if (!(str))
			return (0);
	}
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	idx = numlen(n);
	while (n > 0)
	{
		str[--idx] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}

int	main(void)
{
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa(-0));
	printf("%s\n", ft_itoa(123));
	printf("%s\n", ft_itoa(-123));
}
