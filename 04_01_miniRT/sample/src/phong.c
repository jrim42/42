/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:42:30 by jrim              #+#    #+#             */
/*   Updated: 2022/09/13 15:32:32 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

t_rgb	phong_lighting(t_scene *scene)
{
	t_rgb	light_color;
	t_obj	*lights;

	light_color = rgb_init(0, 0, 0);	//광원이 없는 경우
	lights = scene->light;
	while (lights)
	{
		if (lights->type == LIGHT_PT)
			light_color = vt_plus(light_color, point_light_get(scene, lights->element));
		lights = lights->next;
	}
	light_color = vt_plus(light_color, scene->ambient);
	return (vt_min(vt_multi_2(light_color, scene->rec.albedo), rgb_init(1, 1, 1)));
	//모든 광원에 의한 빛의 양을 구한 후, 오브젝트의 반사율과 곱해준다. 그 값이 (1, 1, 1)을 넘으면 (1, 1, 1)을 반환한다.

}

t_vt	reflect(t_vt v, t_vt n)
{
	return (vt_minus(v, vt_multi(n, vt_dot(v, n) * 2)));
}

t_rgb	point_light_get(t_scene *scene, t_light *light)
{
    t_rgb	diffuse;
    t_vt	light_dir;
    double	kd; // diffuse의 강도
	t_rgb	specular;
    t_vt	view_dir;
    t_vt	reflect_dir;
    double	spec;
    double	ksn;
    double	ks;
	double	brightness;
	double	light_len;
    t_ray	light_ray;

	light_dir = vt_minus(light->orig, scene->rec.p);
    light_len = vt_len(light_dir);
    light_ray = ray(vt_plus(scene->rec.p, vt_multi(scene->rec.norm, EPSILON)), light_dir);
    if (in_shadow(scene->world, light_ray, light_len))
        return (rgb_init(0,0,0));
    light_dir = vt_unit(light_dir);
    // light_dir = vt_unit(vt_minus(light->orig, scene->rec.p)); //교점에서 출발하여 광원을 향하는 벡터(정규화 됨)
    // // cosΘ는 Θ 값이 90도 일 때 0이고 Θ가 둔각이 되면 음수가 되므로 0.0보다 작은 경우는 0.0으로 대체한다.
    kd = fmax(vt_dot(scene->rec.norm, light_dir), 0.0);// (교점에서 출발하여 광원을 향하는 벡터)와 (교점에서의 법선벡터)의 내적값.
    diffuse = vt_multi(light->light_color, kd);
   	view_dir = vt_unit(vt_multi(scene->ray.dir, -1));
    reflect_dir = reflect(vt_multi(light_dir, -1), scene->rec.norm);
    ksn = 64; // shininess value
    ks = 0.5; // specular strength
    spec = pow(fmax(vt_dot(view_dir, reflect_dir), 0.0), ksn);
    specular = vt_multi(vt_multi(light->light_color, ks), spec);
	brightness = light->bright_ratio * LUMEN;
    return (vt_multi(vt_plus(vt_plus(scene->ambient, diffuse), specular), brightness));
}

t_bool	in_shadow(t_obj *objs, t_ray ray, double light_len)
{
	// ray는 hit point에서부터 광원의 원점을 향해 쏴준 ray
	// ray가 obj에 가로막히게 되면 hit point가 그림자 안에 존재하는 것이다.
	t_hit	rec;

	rec.tmin = 0;
	rec.tmax = light_len;	// hit point로부터 광원의 원점까지의 거리
	// tmax가 light_len보다 길 경우 광원 뒤에 다른 obj가 있는 경우에도 shadow가 생기는 현상이 발생한다.
	if (hit(objs, &ray, &rec))
		return (TRUE);
	return (FALSE);
}