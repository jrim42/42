/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _map_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:13:59 by jrim              #+#    #+#             */
/*   Updated: 2022/03/30 17:29:33 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_read(t_game *game, char *map_src);
void	_map_cnt(t_game *game, char *map_src);
void	_map_malloc(t_game *game);

void	map_read(t_game *game, char *map_src)
{
	int		fd;
	int		col_idx;
	int		row_idx;
	char	*line = 0;

	_map_cnt(game, map_src);
	_map_malloc(game);
	game->maps.coord = (char **)malloc(game->maps.cols * sizeof(char *));
	col_idx = -1;
	while (++col_idx < game->maps.cols)
		game->maps.coord[col_idx] = (char *)malloc(game->maps.rows * sizeof(char));
	fd = open(map_src, O_RDONLY);
	col_idx = 0;
	while ((line = get_next_line(fd)) != 0)
	{
		row_idx = 0;
		while (row_idx < game->maps.rows)
		{
			game->maps.coord[col_idx][row_idx] = line[row_idx];
			row_idx++;
		}
		col_idx++;
		free(line);
	}
	close(fd);
}

void	_map_cnt(t_game *game, char *map_src)
{
	int		fd;
	int		tot_cnt;
	int		col_cnt;
	int		row_cnt;
	char	*line = 0;

	fd = open(map_src, O_RDONLY);
	if (fd <= 0)
		err_exit("[error] : file open failed");
	if ((line = get_next_line(fd)) == 0)
		err_exit("[error] : empty map");
	col_cnt = 1;
	row_cnt = ft_strlen(line) - 1;
	tot_cnt = row_cnt;
	while ((line = get_next_line(fd)) != 0)
	{
		tot_cnt += ft_strlen(line) - 1;
		col_cnt++;
		free(line);
	}
	close(fd);
	if ((tot_cnt + 1) % col_cnt != 0)
		err_exit("[error] : map is not rectangle");
	game->maps.cols = col_cnt;
	game->maps.rows = row_cnt;
}

void	_map_malloc(t_game *game)
{
	int		col;
	int		row;
	int		idx;

	col = game->maps.cols;
	row = game->maps.rows;
	game->maps.coord = (char **)malloc(col * sizeof(char *));
	idx = -1;
	while (++idx < col)
		game->maps.coord[idx] = (char *)malloc(row * sizeof(char));
}
