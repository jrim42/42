/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_scene3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:28:57 by jrim              #+#    #+#             */
/*   Updated: 2022/09/18 14:48:38 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

t_scene *scene_init(void)
{
    t_scene		*scene;
    t_obj		*world;
    t_obj		*lights;
    double		ka;

    if(!(scene = (t_scene *)malloc(sizeof(t_scene))))
        return (NULL);
    scene->cnvs = canvas_init(1024, 768);
    // scene->cnvs = canvas_init(400, 300);
    scene->cam = camera_init(&scene->cnvs, pt_init(0, 0, 0));
    world = object_init(PLN, plane_init(pt_init(0, -3, 0), vt_init(0, 1, 0)), rgb_init(0.5, 0.9, 0.5 ));
    // obj_add(&world, object_init(SPH, sphere_init(pt_init(-2, 0, -3), 1), rgb_init(0.9, 0.4, 0.1))); // world 에 구2 추가
    // obj_add(&world, object_init(SPH, sphere_init(pt_init(-1, 2, -5), 1), rgb_init(0.2, 0.4, 0.9))); // world 에 구2 추가
    // obj_add(&world, object_init(SPH, sphere_init(pt_init(1, -1, -3), 1), rgb_init(0.9, 0.9, 0.2))); // world 에 구2 추가
    // obj_add(&world, object_init(PLN, plane_init(pt_init(3, 0, -5), vt_init(-1, 1, 0)), rgb_init(0.2, 0.3, 0.3))); // world 에 구2 추가
    // world = object_init(CYL, cyl_init(pt_init(-2, 0, -4), vt_init(0, 1, 1), 2, 4), rgb_init(0.8, 0.6, 0.2)); // world 에 구2 추가
    // obj_add(&world, object_init(CYL, cyl_init(pt_init(-2, 0, -4), vt_init(0, 1, 1), 2, 4), rgb_init(0.8, 0.6, 0.2))); // world 에 구2 추가
    obj_add(&world, object_init(CYL, cyl_init(pt_init(0, 0, -3), vt_init(0, 1, -1), 1.2, 2), rgb_init(0.3, 0.2, 0.8))); // world 에 구2 추가
    // obj_add(&world, object_init(CYL, cyl_init(pt_init(0, 3, -10), vt_init(0, 0.7, -0.5), 3, 4), rgb_init(0.6, 0.2, 0.3))); // world 에 구2 추가
    // obj_add(&world, object_init(CYL, cyl_init(pt_init(3, 0, -3), vt_init(0, 1, 0), 1, 2), rgb_init(0.6, 0.4, 0.1))); // world 에 구2 추가
    // obj_add(&world, object_init(CYL, cyl_init(pt_init(1.5, 0, -3), vt_init(0, 1, 0), 1, 2), rgb_init(0.6, 0.4, 0.1))); // world 에 구2 추가
    // obj_add(&world, object_init(CYL, cyl_init(pt_init(-0, 0, -3), vt_init(0, 1, 0), 1, 2), rgb_init(0.6, 0.4, 0.1))); // world 에 구2 추가
    // obj_add(&world, object_init(CYL, cyl_init(pt_init(-1.5, 0, -3), vt_init(0, 1, 0), 1, 2), rgb_init(0.6, 0.4, 0.1))); // world 에 구2 추가
    // obj_add(&world, object_init(CYL, cyl_init(pt_init(-3, 0, -3), vt_init(0, 1, 0), 1, 2), rgb_init(0.6, 0.4, 0.1))); // world 에 구2 추가
    scene->world = world;
    lights = object_init(LIGHT_PT, light_point(pt_init(1, 1, 0), rgb_init(1, 1, 1), 0.5), rgb_init(0, 0, 0)); // 더미 albedo
    // lights = object_init(LIGHT_PT, light_point(pt_init(-5, 2, 10), rgb_init(1, 1, 1), 0.5), rgb_init(0, 0, 0)); // 더미 albedo
    scene->light = lights;
    ka = 0.1; 
    scene->ambient = vt_multi(rgb_init(1,1,1), ka); 
    return (scene);
}

int     main(void)
{
    int         i;
    int         j;
    double      u;
    double      v;
    t_rgb		pixel_color;
    t_scene     *scene;

    scene = scene_init();
    printf("P3\n%d %d\n255\n", scene->cnvs.width, scene->cnvs.height);
    j = scene->cnvs.height;
    while (--j >= 0)
    {
        i = -1;
        while (++i < scene->cnvs.width)
        {
            u = (double)i / (scene->cnvs.width - 1);
            v = (double)j / (scene->cnvs.height - 1);
            scene->ray = ray_primary(&scene->cam, u, v);
            pixel_color = ray_color(scene);
            write_color(pixel_color);
        }
    }
    return (0);
}