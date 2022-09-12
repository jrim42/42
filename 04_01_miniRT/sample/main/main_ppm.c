/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ppm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:54:47 by jrim              #+#    #+#             */
/*   Updated: 2022/09/12 17:23:12 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../include/structures.h"
#include "../include/utils.h"
#include "../include/print.h"

int	main(void)
{
    int     canvas_width;
    int     canvas_height;
    int     i;
    int     j;
	t_rgb	color;

    //캔버스의 가로, 세로 픽셀값
    canvas_width = 256;
    canvas_height = 256;

    // 랜더링
    // P3 는 색상값이 아스키코드라는 뜻, 그리고 다음 줄은 캔버스의 가로, 세로 픽셀 수, 마지막은 사용할 색상값
    printf("P3\n%d %d\n255\n", canvas_width, canvas_height);
    j = canvas_height;
    while (--j >= 0)
    {
        i = -1;
        while (++i < canvas_width)
        {
            color.x = (double)i / (canvas_width - 1);
			color.y = (double)j / (canvas_height - 1);
            color.z = 0.25;
            write_color(color);
        }
    }
    return (0);
}