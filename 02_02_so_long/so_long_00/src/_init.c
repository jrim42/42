/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _init.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:13:30 by jrim              #+#    #+#             */
/*   Updated: 2022/04/03 14:28:17 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init(t_game *game);
void	img_init(t_game *game);
void	player_init(t_game *game, t_player *player);

void	game_init(t_game *game)
{
	int	width;
	int	height;

	game->mlx = mlx_init();
	width = game->maps.rows * TILES;
	height = game->maps.cols * TILES;
	game->win = mlx_new_window(game->mlx, width, height, "so_long");
	game->end = 0;
	img_init(game);
	player_init(game, &game->player);
}

void	img_init(t_game *game)
{
	game->road.ptr = ft_xpm_to_img(game, "img/road.xpm");
	game->wall.ptr = ft_xpm_to_img(game, "img/wall.xpm");
	game->exit.ptr = ft_xpm_to_img(game, "img/exit.xpm");
	game->collec.ptr = ft_xpm_to_img(game, "img/collector.xpm");
	game->player.p_img.ptr = ft_xpm_to_img(game, "img/player.xpm");
}

void	player_init(t_game *game, t_player *player)
{
	char	**map;
	int		x;
	int		y;

	player->step = 0;
	player->collec = 0;
	player->dir = -1;
	map = game->maps.coord;
	y = 0;
	while (y < game->maps.cols)
	{
		x = 0;
		while (x < game->maps.rows)
		{
			if (map[y][x] == 'P')
			{
				player->x_pos = x;
				player->y_pos = y;
			}
			else if (map[y][x] == 'E')
			{
				player->x_end = x;
				player->y_end = y;
			}
			x++;
		}
		y++;
	}
	printf("start : (%d, %d)\n", player->x_pos, player->y_pos);
	printf("end : (%d, %d)\n", player->x_end, player->y_end);
}
