/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _map_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:13:59 by jrim              #+#    #+#             */
/*   Updated: 2022/03/21 20:41:01 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_read(t_game *game, char *map_src);
void 	map_parse(t_game *game);

void	map_read(t_game *game, char *map_src)
{
	int		fd;
	int		idx_1;
	int		idx_2;
	char	*line = 0;

	fd = open(map_src, O_RDONLY);
	if (fd <= 0)
		err_exit("[error] : file open failed");
	game->maps.cols = COL;
	game->maps.rows = ROW;
	game->maps.coord = (char **)malloc(COL * sizeof(char *));
	idx_1 = -1;
	while (++idx_1 < ROW)
		game->maps.coord[idx_1] = (char *)malloc(ROW * sizeof(char));
	idx_1 = 0;
	while ((line = get_next_line(fd)) != 0)
	{
		idx_2 = 0;
		while (idx_2 < ROW)
		{
			game->maps.coord[idx_1][idx_2] = line[idx_2];
			printf("%c", game->maps.coord[idx_1][idx_2]);
			idx_2++;
		}
		printf("\n");
		idx_1++;
		free(line);
	}
	close(fd);
}

void map_parse(t_game *game)
{
	if (game)
		return;
}