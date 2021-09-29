/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 22:58:02 by jrim              #+#    #+#             */
/*   Updated: 2021/09/29 19:20:54 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "find_map.h"

int	get_copy(char *ch_map, unsigned int **num_map, t_map_info g_info)
{
	int	size;
	int	index;

	size = g_info.lines * g_info.line_size;
	*num_map = (unsigned int *)malloc(sizeof(unsigned int) * size);
	if (!num_map)
		return (0);
	index = 0;
	while (index < size)
	{
		*(*num_map + index) = ch_map[g_info.first_line + index];
		index++;
	}
	return (1);
}

int	put_nbr(unsigned int *num_map, t_map_info g_info)
{
	int		index;
	int		index_eol;
	char	ch;

	index_eol = g_info.line_size - 1;
	index = 0;
	while (index < g_info.lines * g_info.line_size)
	{
		ch = num_map[index];
		if (ch == g_info.ch[0])
			num_map[index] = '1';
		else if (ch == g_info.ch[1])
			num_map[index] = '0';
		else if (ch == '\n' && index == index_eol)
			index_eol += g_info.line_size;
		else
			return (0);
		index++;
	}
	return (1);
}
