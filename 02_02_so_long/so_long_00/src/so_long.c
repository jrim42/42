/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 21:28:27 by jrim              #+#    #+#             */
/*   Updated: 2022/03/21 18:18:52 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		main_loop(t_game *game);
void	init_game(t_game *game);
int		press_key(int keycode);

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
	map_gen(game);
	return (0);
}

void	init_game(t_game *game)
{
	int	width;
	int	height;

	game->mlx = mlx_init();
	width = COL * TILES;
	height = ROW * TILES;
	game->win = mlx_new_window(game->mlx, width, height, "so_long");
	map_elm_init(game);
}

int	press_key(int keycode)
{
	if (keycode == KEYCODE_EXIT)
		exit(0);
	return (0);
}
