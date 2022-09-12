/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:28:57 by jrim              #+#    #+#             */
/*   Updated: 2022/09/12 21:39:32 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

t_scene *scene_init(void)
{
    t_scene		*scene;
    t_obj		*world;
    t_obj		*lights;
    double		ka; // 8.4 에서 설명

    // malloc 할당 실패 시, 실습에서는 return NULL로 해두었지만, 적절한 에러 처리가 필요하다.
    if(!(scene = (t_scene *)malloc(sizeof(t_scene))))
        return (NULL);
    scene->cnvs = canvas_init(400, 300);
    scene->cam = camera_init(&scene->cnvs, pt_init(0, 0, 0));
    world = object_init(SPH, sphere_init(pt_init(-2, 0, -5), 2), rgb_init(0.5, 0, 0)); // world 에 구1 추가
    obj_add(&world, object_init(SPH, sphere_init(pt_init(2, 0, -5), 2), rgb_init(0, 0.5, 0))); // world 에 구2 추가
    obj_add(&world, object_init(SPH, sphere_init(pt_init(0, -1000, 0), 999), rgb_init(1, 1, 1))); // world 에 구3 추가
    scene->world = world;
    lights = object_init(LIGHT_PT, light_point(pt_init(0, 5, 0), rgb_init(1, 1, 1), 0.5), rgb_init(0, 0, 0)); // 더미 albedo
    scene->light = lights;
    ka = 0.1; // 8.4 에서 설명
    scene->ambient = vt_multi(rgb_init(1,1,1), ka); // 8.4 에서 설명
    return (scene);
}
/* * * * 추가 끝 * * * */

int     main(void)
{
    int         i;
    int         j;
    double      u;
    double      v;
    t_rgb		pixel_color;
    /* * * * 수정 * * * */
    t_scene     *scene;

    scene = scene_init();
    // 랜더링
    // P3 는 색상값이 아스키코드라는 뜻, 그리고 다음 줄은 캔버스의 가로, 세로 픽셀 수, 마지막은 사용할 색상값
    /* * * * 수정 * * * */
    printf("P3\n%d %d\n255\n", scene->cnvs.width, scene->cnvs.height);
    j = scene->cnvs.height - 1;
    while (j >= 0)
    {
        i = 0;
        while (i < scene->cnvs.width)
        {
            u = (double)i / (scene->cnvs.width - 1);
            v = (double)j / (scene->cnvs.height - 1);
            //ray from camera origin to pixel
            scene->ray = ray_primary(&scene->cam, u, v);
            pixel_color = ray_color(scene);
            // ray_color함수의 인자도 ray, world를 모두 담고 있는 scene으로 바꿨다.
    /* * * * 수정 끝 * * * */
            write_color(pixel_color);
            ++i;
        }
        --j;
    }
    return (0);
}