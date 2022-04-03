/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _img_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:13:52 by jrim              #+#    #+#             */
/*   Updated: 2022/04/02 18:19:22 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_xpm_to_img(t_game *game, char *str);
void	ft_put_img64(t_game *game, void *img_ptr, int x, int y);

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
