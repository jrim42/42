/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 21:21:28 by jrim              #+#    #+#             */
/*   Updated: 2021/09/30 00:01:07 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "find_map.h"

int	main(int argc, char *argv[])
{
	int		index;
	char	*ch_map;

	if (argc < 2)
	{
		ch_map = get_ch_map();
		if (!ch_map)
			write(1, "map error\n", 10);
		else
			solve_map(ch_map);
	}
	else
	{
		index = 1;
		while (index < argc)
		{
			if (!file_to_ch_map(&ch_map, argv[index]))
				write(1, "map error\n", 10);
			else
				solve_map(ch_map);
			if (++index != argc)
				write(1, "\n", 1);
		}
	}
	return (0);
}

int	file_to_ch_map(char **ch_map, char *file)
{
	int		fd;
	int		byte;
	int		size;
	char	buff[1000];

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	byte = read(fd, buff, 1000);
	size = byte;
	while (byte)
	{
		byte = read(fd, buff, 1000);
		size += byte;
	}
	*ch_map = (char *)malloc(sizeof(char) * size + 1);
	if (!ch_map)
		return (0);
	close(fd);
	fd = open(file, O_RDONLY);
	read(fd, *ch_map, size);
	*(*ch_map + size) = '\0';
	close(fd);
	return (1);
}

void	solve_map(char *ch_map)
{
	unsigned int	*num_map;
	t_map_info		g_info;

	if (is_map_valid(ch_map, &g_info))
	{
		if (!get_copy(ch_map, &num_map, g_info))
			return ;
		if (!put_nbr(num_map, g_info))
			write(1, "map error\n", 10);
		else
			find_square(ch_map, num_map, g_info);
		free(num_map);
	}
	else
		write(1, "map error\n", 10);
	free(ch_map);
}

int	is_map_valid(char *ch_map, t_map_info *g_info)
{
	if (!get_first_line(ch_map, g_info))
		return (0);
	if (!(get_lines(ch_map, g_info) && get_chars(ch_map, g_info) && \
				get_line_size(ch_map, g_info) && \
				check_line_size(ch_map, g_info)))
		return (0);
	return (1);
}
