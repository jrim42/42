/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_and_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 21:28:18 by jrim              #+#    #+#             */
/*   Updated: 2021/09/29 19:21:06 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "find_map.h"

void	find_square(char *ch_map, unsigned int *num_map, t_map_info g_info)
{
	int	row;
	int	col;
	int	max_idx;
	int	max_val;

	row = 1;
	while (row < g_info.lines)
	{
		col = 1;
		while (col < g_info.line_size - 1)
		{
			if (num_map[row * g_info.line_size + col] != '0')
				num_map[row * g_info.line_size + col] \
					= search_min(row, col, num_map, g_info) + 1;
			col++;
		}
		row++;
	}
	max_val = search_max(&max_idx, num_map, g_info);
	display_result(max_idx, max_val, ch_map, g_info);
}

int	search_min(int row, int col, unsigned int *num_map, t_map_info g_info)
{
	int	min;
	int	left_dia;
	int	up;
	int	left;

	min = 9999999;
	left_dia = num_map[((row - 1) * g_info.line_size) + (col - 1)];
	up = num_map[((row - 1) * g_info.line_size) + col];
	left = num_map[row * g_info.line_size + (col - 1)];
	if (left_dia < min)
		min = left_dia;
	if (up < min)
		min = up;
	if (left < min)
		min = left;
	return (min);
}

unsigned int	search_max(int *max_idx, \
		unsigned int *num_map, t_map_info g_info)
{
	int				i;
	unsigned int	max_val;

	i = 0;
	max_val = 0;
	while (i < g_info.lines * g_info.line_size)
	{
		if (num_map[i] > max_val)
		{
			max_val = num_map[i];
			*max_idx = i;
		}
		i++;
	}
	return (max_val - '0');
}

void	display_result(int max_idx, int max_val, \
		char *ch_map, t_map_info g_info)
{
	int	row;
	int	col;

	row = 0;
	while (row < max_val)
	{
		col = 0;
		while (col < max_val)
		{
			ch_map[g_info.first_line + max_idx - row * \
				g_info.line_size - col] = g_info.ch[2];
			col++;
		}
		row++;
	}
	write(1, ch_map + g_info.first_line, g_info.lines * g_info.line_size);
}
