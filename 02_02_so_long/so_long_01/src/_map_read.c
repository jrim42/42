/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _map_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:13:59 by jrim              #+#    #+#             */
/*   Updated: 2022/05/01 22:57:39 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_read(t_game *game, char *map_src);
void	_map_cnt(t_game *game, char *map_src);
void	_map_malloc(t_game *game);

void	map_read(t_game *game, char *map_src)
{
	int		fd;
	int		x;
	int		y;
	char	*line;

	_map_cnt(game, map_src);
	_map_malloc(game);
	game->maps.coord = (char **)malloc(game->maps.cols * sizeof(char *));
	y = -1;
	while (++y < game->maps.cols)
		game->maps.coord[y] = (char *)malloc(game->maps.rows * sizeof(char));
	fd = open(map_src, O_RDONLY);
	y = -1;
	while (++y < game->maps.cols)
	{
		line = get_next_line(fd);
		x = -1;
		while (++x < game->maps.rows)
			game->maps.coord[y][x] = line[x];
		free(line);
	}
	close(fd);
}

void	_map_cnt(t_game *game, char *map_src)
{
	int		fd;
	char	*line;
	int		tot_cnt;
	int		col_cnt;
	int		row_cnt;

	fd = open(map_src, O_RDONLY);
	if (fd <= 0)
		msg_err("[error] : file open failed");
	line = get_next_line(fd);
	if (line == NULL)
		msg_err("[error] : empty map");
	col_cnt = 0;
	row_cnt = ft_strlen(line) - 1;
	tot_cnt = row_cnt;
	while (line != 0)
	{
		tot_cnt += ft_strlen(line) - 1;
		col_cnt++;
		//이전 line과 글자수 같은지 확인하기
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	if ((tot_cnt + 1) % col_cnt != 0)
		msg_err("[error] : map is not rectangle");
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
