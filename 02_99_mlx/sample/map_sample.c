/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_sample.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 21:28:27 by jrim              #+#    #+#             */
/*   Updated: 2022/03/14 23:39:53 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "help.h"

int main(void)
{
	t_game game;

	init_map(&game);
	init_game(&game);
	mlx_hook(game.win, X_EVENT_KEYPRESS, 0, &press_key, &game);
	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}

int	main_loop(t_game *game)
{
	draw_map(game);
	return (0);
}

void	draw_map(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->maps.rows)
	{
		j = 0;
		while (j < game->maps.cols)
		{
			if (game->maps.coord[i][j] == 0)
				ft_put_img64(game, game->road.ptr, j, i);
			else if (game->maps.coord[i][j] == 1)
				ft_put_img64(game, game->wall.ptr, j, i);
			else if (game->maps.coord[i][j] == 2)
				ft_put_img64(game, game->player.ptr, j, i);
			j++;
		}
		i++;
	}
}

void	init_game(t_game *game)
{
	//init_window(game);
	int	width;
	int	height;

	game->mlx = mlx_init();
	width = COL * TILES;
	height = ROW * TILES;
	game->win = mlx_new_window(game->mlx, width, height, "so_long");
	
	//init_img(game);
	game->road.ptr = ft_xpm_to_img(game, "road.xpm");
	game->wall.ptr = ft_xpm_to_img(game, "wall.xpm");
	game->player.ptr = ft_xpm_to_img(game, "player.xpm");
}

void	*ft_xpm_to_img(t_game *game, char *str)
{
	void	*img;

	img = mlx_xpm_file_to_image(game->mlx, str, &(game->img64.w), &(game->img64.h));
	return (img);
}

void	ft_put_img64(t_game *game, void *img_ptr, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img_ptr, x * TILES, y * TILES);
}

void init_map(t_game *game)
{
	game->maps.cols = COL;
	game->maps.rows = ROW;
	int src[ROW][COL] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1},
	{1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1},
	{1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1},
	{1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1},
	{1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1},
	{1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1},
	{1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
	{1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 2, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
	memcpy(game->maps.coord, src, sizeof(int) * ROW * COL);
}

int	press_key(int keycode)
{
	if (keycode == KEYCODE_EXIT)
		exit(0);
	return (0);
}
