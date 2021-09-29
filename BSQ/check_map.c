/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 21:25:46 by jrim              #+#    #+#             */
/*   Updated: 2021/09/29 21:14:46 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "find_map.h"

int	get_first_line(char *ch_map, t_map_info *g_info)
{
	int		size;

	size = 0;
	while (ch_map[size] != '\n' && ch_map[size] != '\0')
		size++;
	g_info->first_line = size + 1;
	if (size + 1 < 5)
		return (0);
	return (1);
}

int	get_line_size(char *ch_map, t_map_info *g_info)
{
	int		size;

	size = 0;
	while (ch_map[g_info->first_line + size] != '\n')
		size++;
	g_info->line_size = size + 1;
	if (g_info->line_size < 2)
		return (0);
	return (1);
}

int	get_lines(char *ch_map, t_map_info *g_info)
{
	int		index;
	int		lines;
	int		digit;

	digit = 1;
	lines = 0;
	index = g_info->first_line - 5;
	while (index >= 0)
	{
		if (!(ch_map[index] >= '0' && ch_map[index] <= '9'))
			return (0);
		lines += (ch_map[index--] - 48) * digit;
		digit *= 10;
	}
	g_info->lines = lines;
	if (!lines)
		return (0);
	return (1);
}

int	get_chars(char *ch_map, t_map_info *g_info)
{
	int		index;

	index = 0;
	while (index < 3)
	{
		g_info->ch[index] = ch_map[g_info->first_line - 4 + index];
		if (!(g_info->ch[index] >= 32 && g_info->ch[index] <= 126))
			return (0);
		index++;
	}
	if (g_info->ch[0] == g_info->ch[1] || g_info->ch[0] == g_info->ch[2]
		|| g_info->ch[1] == g_info->ch[2])
		return (0);
	return (1);
}

int	check_line_size(char *ch_map, t_map_info *g_info)
{
	int		count;

	count = 1;
	while (count < g_info->lines)
	{
		if (ch_map[g_info->first_line + count * \
				g_info->line_size + g_info->line_size - 1] != '\n')
			return (0);
		count++;
	}
	if (ch_map[g_info->first_line + count * g_info->line_size] != '\0')
		return (0);
	return (1);
}
