/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_get_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 21:26:18 by jrim              #+#    #+#             */
/*   Updated: 2022/03/11 14:35:07 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "help.h"

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

// int main(void)
// {
// 	void *mlx_ptr;
// 	void *win_ptr;
// 	t_param param;
	
// 	mlx_ptr = mlx_init();
// 	param_init(&param);
// 	win_ptr = mlx_new_window(mlx_ptr, 300, 300, "Hello, World!");
// 	mlx_hook(win_ptr, X_EVENT_KEY_PRESS, 0, &key_press, &param); // 키를 잡는 함수
// 	mlx_loop(mlx_ptr);
// 	return (0);
// }