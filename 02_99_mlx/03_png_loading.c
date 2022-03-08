/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_png_loading.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 21:27:29 by jrim              #+#    #+#             */
/*   Updated: 2022/03/08 21:27:31 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <mlx.h>

int main(void)
{
	void *mlx_ptr;
	void *win_ptr;
	void *img_ptr;  // 이미지를 저장할 포인터
	int width;  // 이미지의 너비
	int height; // 이미지의 높이

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "load image!");
	img_ptr = mlx_xpm_file_to_image(mlx_ptr, "../textures/wall_s.xpm", &width, &height);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
	mlx_loop(mlx_ptr);
	return (0);
}
