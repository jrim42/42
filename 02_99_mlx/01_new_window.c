/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_new_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 21:25:09 by jrim              #+#    #+#             */
/*   Updated: 2022/03/11 14:33:46 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "help.h"

int main(void)
{
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "new window sample");
	mlx_loop(mlx_ptr);
}

//compile option
// cc -I /usr/local/include/ main.c -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
// -I: 헤더파일 위치를 지정하는 컴파일 옵션
// -L: 라이브러리파일 위치를 지정하는 컴파일 옵션
// cc -lmlx main.c
// 이런 식으로 해도 되긴 된다.

//https://velog.io/@jeunghoon/MiniLibX%EB%A5%BC-%EC%9D%B4%EC%9A%A9%ED%95%B4-%EC%83%88-%EC%B0%BD%EC%9D%84-%EC%83%9D%EC%84%B1%ED%95%98%EC%9E%90