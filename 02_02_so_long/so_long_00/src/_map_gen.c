/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _map_gen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:05:42 by jrim              #+#    #+#             */
/*   Updated: 2022/04/26 21:17:45 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_gen(t_game *game);

void	map_gen(t_game *game)
{
	int		x;
	int		y;

	y = 0;
	while (y < game->maps.cols)
	{
		x = 0;
		while (x < game->maps.rows)
		{
			if (game->maps.coord[y][x] == '0')
				ft_put_img(game, game->road.ptr, x, y);
			else if (game->maps.coord[y][x] == '1')
				ft_put_img(game, game->wall.ptr, x, y);
			else if (game->maps.coord[y][x] == 'P')
				ft_put_img(game, game->player.p_img.ptr, x, y);
			else if (game->maps.coord[y][x] == 'E')
				ft_put_img(game, game->exit.ptr, x, y);
			else if (game->maps.coord[y][x] == 'C')
				ft_put_img(game, game->collec.ptr, x, y);
			x++;
		}
		y++;
	}
}
