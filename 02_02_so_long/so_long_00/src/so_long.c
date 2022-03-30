/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 21:28:27 by jrim              #+#    #+#             */
/*   Updated: 2022/03/30 17:31:16 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game);
void	err_exit(char *msg);
int		main_loop(t_game *game);

int main(int argc, char **argv)
{
	t_game game;

	if (argc != 2)
		err_exit("[usage]: ./so_long [FILENAME.ber]");
	map_read(&game, argv[1]);
	map_check(&game, game.maps.coord);
	init_game(&game);
	map_gen(&game);
	mlx_hook(game.win, X_EVENT_KEYPRESS, 0, &key_press, &game);
	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}

void	init_game(t_game *game)
{
	int	width;
	int	height;

	game->mlx = mlx_init();
	width = game->maps.rows * TILES;
	height = game->maps.cols * TILES;
	game->win = mlx_new_window(game->mlx, width, height, "so_long");
}

void	err_exit(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(1);
}

int	main_loop(t_game *game)
{
	map_gen(game);
	return (0);
}

