/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _map_gen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:05:42 by jrim              #+#    #+#             */
/*   Updated: 2022/04/03 14:25:56 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_gen(t_game *game);

void	map_gen(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->maps.rows)
	{
		j = 0;
		while (j < game->maps.cols)
		{
			if (game->maps.coord[i][j] == '0')
				ft_put_img64(game, game->road.ptr, j, i);
			else if (game->maps.coord[i][j] == '1')
				ft_put_img64(game, game->wall.ptr, j, i);
			else if (game->maps.coord[i][j] == 'P')
				ft_put_img64(game, game->player.p_img.ptr, j, i);
			else if (game->maps.coord[i][j] == 'E')
				ft_put_img64(game, game->exit.ptr, j, i);
			else if (game->maps.coord[i][j] == 'C')
				ft_put_img64(game, game->collec.ptr, j, i);
			j++;
		}
		i++;
	}
}
