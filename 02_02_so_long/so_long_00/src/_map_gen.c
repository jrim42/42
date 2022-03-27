/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _map_gen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:05:42 by jrim              #+#    #+#             */
/*   Updated: 2022/03/27 23:05:39 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_gen(t_game *game);
void    img_init(t_game *game);
void	*ft_xpm_to_img(t_game *game, char *str);
void	ft_put_img64(t_game *game, void *img_ptr, int x, int y);

void	map_gen(t_game *game)
{
	int		i;
	int		j;

	img_init(game);
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
				ft_put_img64(game, game->player.ptr, j, i);
			else if (game->maps.coord[i][j] == 'E')
				ft_put_img64(game, game->exit.ptr, j, i);
			else if (game->maps.coord[i][j] == 'C')
				ft_put_img64(game, game->collec.ptr, j, i);
			j++;
		}
		i++;
	}
}

void    img_init(t_game *game)
{
    game->road.ptr = ft_xpm_to_img(game, "img/road.xpm");
	game->wall.ptr = ft_xpm_to_img(game, "img/wall.xpm");
    game->exit.ptr = ft_xpm_to_img(game, "img/exit.xpm");
    game->collec.ptr = ft_xpm_to_img(game, "img/collector.xpm");
	game->player.ptr = ft_xpm_to_img(game, "img/player.xpm");
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