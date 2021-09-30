/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 14:38:15 by jrim              #+#    #+#             */
/*   Updated: 2021/09/25 19:25:17 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void				ft_putstr(char *str);
void				ft_putchar(char c);
void				ft_display_size(int nb);

void	ft_show_tab(struct s_stock_str *par)
{
	int	cnt;

	cnt = 0;
	while (par[cnt].str != 0)
	{
		ft_putstr(par[cnt].str);
		write(1, "\n", 1);
		ft_display_size(par[cnt].size);
		write(1, "\n", 1);
		ft_putstr(par[cnt].copy);
		write(1, "\n", 1);
		cnt++;
	}
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		write(1, &str[i++], 1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_display_size(int nb)
{
	char	arr[10];
	int		i;

	i = 0;
	if (nb == 0)
		ft_putchar('0');
	while (nb > 0)
	{
		arr[i] = (nb % 10);
		nb /= 10;
		i++;
	}
	while (i-- > 0)
		ft_putchar(arr[i] + 48);
}
