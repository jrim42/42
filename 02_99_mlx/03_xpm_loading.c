/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_xpm_loading.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 21:27:29 by jrim              #+#    #+#             */
/*   Updated: 2022/03/11 17:02:33 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "help.h"

int main(void)
{
	void *mlx_ptr;
	void *win_ptr;
	void *img_ptr;  // 이미지를 저장할 포인터
	int width;  // 이미지의 너비
	int height; // 이미지의 높이
	t_param param;

	mlx_ptr = mlx_init();
	param_init(&param);
	win_ptr = mlx_new_window(mlx_ptr, 800, 800, "load image");
	img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./img/img15.xpm", &width, &height);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 400, 400);
	mlx_hook(win_ptr, X_EVENT_KEY_PRESS, 0, &key_press, &param);
	mlx_loop(mlx_ptr);
	return (0);
}
