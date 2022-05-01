/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _utils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 19:32:21 by jrim              #+#    #+#             */
/*   Updated: 2022/05/01 16:50:25 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	err_exit(char *msg);
void	_msg_display(char *msg1, int num, char *msg2);
void	*ft_xpm_to_img(t_game *game, char *str);
void	ft_put_img(t_game *game, void *img_ptr, int x, int y);

void	err_exit(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(1);
}

void	_msg_display(char *msg1, int num, char *msg2)
{
	if (msg1 != 0)
		ft_putstr_fd(msg1, 1);
	ft_putnbr_fd(num, 1);
	if (msg2 != 0)
		ft_putstr_fd(msg2, 1);
	write(1, "\n", 1);
}

void	*ft_xpm_to_img(t_game *game, char *str)
{
	void	*img;

	img = mlx_xpm_file_to_image(game->mlx, str, &(game->img64.w), &(game->img64.h));
	return (img);
}

void	ft_put_img(t_game *game, void *img_ptr, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img_ptr, x * TILES, y * TILES);
}
