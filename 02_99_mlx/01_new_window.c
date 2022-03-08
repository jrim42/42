/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_new_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 21:25:09 by jrim              #+#    #+#             */
/*   Updated: 2022/03/08 21:25:40 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

int main(void)
{
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	mlx_loop(mlx_ptr);
}

//compile option
// cc -I /usr/local/include/ main.c -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
// -I: 헤더파일 위치를 지정하는 컴파일 옵션
// -L: 라이브러리파일 위치를 지정하는 컴파일 옵션
// cc -lmlx main.c
// 이런 식으로 해도 되긴 된다.