/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:56:43 by jrim              #+#    #+#             */
/*   Updated: 2021/09/20 18:36:07 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_display_nbr(int nbr, char *base, int base_len, int flag)
{
	char	arr[32];
	int		idx[2];

	idx[0] = 0;
	idx[1] = 0;
	while (nbr > 0)
	{
		arr[idx[0]++] = base[nbr % base_len];
		nbr /= base_len;
	}
	if (flag == 1)
	{
		arr[idx[1]]++;
		while (idx[1] < idx[0])
		{
			if (arr[idx[1]] == base[base_len - 1] + 1)
			{
				arr[idx[1]] = base[0];
				arr[idx[1] + 1]++;
			}
			idx[1]++;
		}
	}
	while (idx[0] > 0)
		write(1, &arr[--idx[0]], 1);
}

int	is_base_dup(char *base, int base_len)
{
	int	i;
	int	j;

	i = 0;
	while (i < base_len - 1)
	{
		j = i + 1;
		while (j < base_len)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_base_valid(char *base, int base_len)
{
	int	i;

	i = 0;
	if (base_len <= 1)
		return (0);
	while (i < base_len)
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	if (is_base_dup(base, base_len) == 0)
		return (0);
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_len;

	base_len = ft_strlen(base);
	if (is_base_valid(base, base_len) == 0)
		return ;
	else if (nbr < 0)
	{
		write(1, "-", 1);
		if (nbr == -2147483648)
			ft_display_nbr(2147483647, base, base_len, 1);
		else
			ft_display_nbr(-nbr, base, base_len, 0);
	}
	else if (nbr == 0)
		write(1, &base[0], 1);
	else
		ft_display_nbr(nbr, base, base_len, 0);
}
