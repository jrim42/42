/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_cnvs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:18:12 by jrim              #+#    #+#             */
/*   Updated: 2022/09/12 18:29:43 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

int main(void)
{
    int		i;
    int		j;
    double	u;
    double	v;
    t_rgb	pixel_color;
    t_cnvs	cnvs;
    t_cam	cam;
    t_ray	ray;
    t_sph   sph;

    //Scene setting;
    cnvs = canvas_init(400, 300);
    cam = camera_init(&cnvs, pt_init(0, 0, 0));
    sph = sphere_init(pt_init(0, 0, -5), 2);

    // 랜더링
    // P3 는 색상값이 아스키코드라는 뜻, 그리고 다음 줄은 캔버스의 가로, 세로 픽셀 수, 마지막은 사용할 색상값
    printf("P3\n%d %d\n255\n", cnvs.width, cnvs.height);
    j = cnvs.height;
    while (--j >= 0)
    {
        i = -1;
        while (++i < cnvs.width)
        {
            u = (double)i / (cnvs.width - 1);
            v = (double)j / (cnvs.height - 1);
            //ray from camera origin to pixel
            ray = ray_primary(&cam, u, v);
            pixel_color = ray_color(&ray, &sph);
            write_color(pixel_color);
        }
    }
}
