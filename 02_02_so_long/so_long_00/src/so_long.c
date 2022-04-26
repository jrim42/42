/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 21:28:27 by jrim              #+#    #+#             */
/*   Updated: 2022/04/26 19:27:09 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	err_exit(char *msg);
int		main_loop(t_game *game);
int		game_end(t_game *game);

int main(int argc, char **argv)
{
	t_game game;

	if (argc != 2)
		err_exit("[usage]: ./so_long [FILENAME.ber]");
	map_read(&game, argv[1]);
	map_check(&game, game.maps.coord);
	game_init(&game);
	mlx_hook(game.win, X_EVENT_KEYPRESS, 0, &key_press, &game);
	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}

void	err_exit(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(1);
}

int	main_loop(t_game *game)
{
	map_gen(game);
	if (game->end == 1)
		game_end(game);
	return (0);
}

int	game_end(t_game *game)
{
	printf("congrats!\n");
	printf("total step : %d\n", game->player.step);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}