/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_png_loading.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 21:27:29 by jrim              #+#    #+#             */
/*   Updated: 2022/03/11 14:25:08 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <mlx.h>
#include "help.h"

void param_init(t_param *param); // 구조체 param 초기화 함수
int key_press(int keycode, t_param *param); // 어떤 키가 눌렸는지 판단하고, 정의된 행동 수행

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
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "load image!");
	img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./img/img.xpm", &width, &height);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
	mlx_hook(win_ptr, X_EVENT_KEY_PRESS, 0, &key_press, &param);
	mlx_loop(mlx_ptr);
	return (0);
}

void param_init(t_param *param) // 구조체 param 초기화 함수
{
	param->x = 0;
	param->y = 0;
}

int key_press(int keycode, t_param *param) // 어떤 키가 눌렸는지 판단하고,
{                                                // 정의된 행동을 수행하는 함수
	if (keycode == KEY_W)        // W 키를 누르면 param.x값이 1 증가한다.
		param->x++;
	else if (keycode == KEY_S)   // S 키를 누르면 param.x값이 1 감소한다.
		param->x--;
	else if (keycode == KEY_A)   // A 키를 누르면 param.y값이 1 증가한다.
		param->y++;
	else if (keycode == KEY_D)   // D 키를 누르면 param.y값이 1 감소한다.
		param->y--;
	else if (keycode == KEY_ESC) // ESC 키를 누르면 프로그램 종료
		exit(0);
	printf("(x, y): (%d, %d)\n", param->x, param->y); // param의 값 확인
	return (0);
}