/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 14:37:55 by jrim              #+#    #+#             */
/*   Updated: 2021/09/27 09:22:34 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

char	*ft_strdup(char *src);
int		ft_strlen(char *str);

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*par;
	int					cnt;
	int					i;

	cnt = 0;
	par = (struct s_stock_str *)malloc((ac + 1) * sizeof(struct s_stock_str));
	if (!(par))
		return (0);
	while (cnt < ac)
	{
		i = 0;
		par[cnt].size = ft_strlen(av[cnt]);
		par[cnt].str = av[cnt];
		par[cnt].copy = ft_strdup(av[cnt]);
		cnt++;
	}
	par[cnt].str = 0;
	return (par);
}

char	*ft_strdup(char *src)
{
	int		src_len;
	int		i;
	char	*dupstr;

	src_len = ft_strlen(src);
	dupstr = (char *)malloc((src_len + 1) * sizeof(char));
	if (!(dupstr))
		return (0);
	i = 0;
	while (i < src_len)
	{
		dupstr[i] = src[i];
		i++;
	}
	dupstr[src_len] = '\0';
	return (dupstr);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
