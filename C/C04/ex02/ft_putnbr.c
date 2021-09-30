/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:23:50 by jrim              #+#    #+#             */
/*   Updated: 2021/09/20 15:24:55 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_display_nbr(int nb)
{
	char	arr[10];
	int		i;

	i = 0;
	while (nb > 0)
	{
		arr[i] = (nb % 10);
		nb /= 10;
		i++;
	}
	while (i > 0)
	{
		i--;
		ft_putchar(arr[i] + 48);
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_display_nbr(-nb);
	}
	else if (nb == 0)
	{
		ft_putchar('0');
	}
	else
	{
		ft_display_nbr(nb);
	}
}
