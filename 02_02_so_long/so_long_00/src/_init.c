/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _init.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:13:30 by jrim              #+#    #+#             */
/*   Updated: 2022/04/02 17:30:41 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init(t_game *game);
void    img_init(t_game *game);

void	game_init(t_game *game)
{
	int	width;
	int	height;

	game->mlx = mlx_init();
	width = game->maps.rows * TILES;
	height = game->maps.cols * TILES;
	game->win = mlx_new_window(game->mlx, width, height, "so_long");
}

void    img_init(t_game *game)
{
    game->road.ptr = ft_xpm_to_img(game, "img/road.xpm");
	game->wall.ptr = ft_xpm_to_img(game, "img/wall.xpm");
    game->exit.ptr = ft_xpm_to_img(game, "img/exit.xpm");
    game->collec.ptr = ft_xpm_to_img(game, "img/collector.xpm");
	game->player.p_img->ptr = ft_xpm_to_img(game, "img/player.xpm");
}