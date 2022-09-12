/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:11:18 by jrim              #+#    #+#             */
/*   Updated: 2022/09/12 20:52:49 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

//ray 생성자(정규화 된 ray)
t_ray	ray(t_pt orig, t_vt dir)
{
    t_ray	ray;

    ray.orig = orig;
    ray.dir = vt_unit(dir);
    return (ray);
}

//ray origin point 부터 방향벡터 ray dir * t 만큼 떨어진 점.
t_pt	ray_at(t_ray *ray, double t)
{
    t_pt	at;

    at = vt_plus(ray->orig, vt_multi(ray->dir, t));
    return (at);
}

// 가장 처음 카메라에서 출발한 광선
t_ray	ray_primary(t_cam *cam, double u, double v)
{
    t_ray   ray;

    ray.orig = cam->orig;
    // left_bottom + u * horizontal + v * vertical - origin 의 단위 벡터.
    ray.dir = vt_unit(vt_minus(vt_plus(vt_plus(cam->left_bot, vt_multi(cam->hori, u)), vt_multi(cam->verti, v)), cam->orig));
    return (ray);
}

t_rgb    ray_color(t_ray *ray, t_obj *obj)
{
    double  t;
    // t_vt    norm;
    t_hit   rec;

    rec.tmin = 0;
    rec.tmax = INFINITY;
    if (hit(obj, ray, &rec))
        return (vt_multi(vt_plus(rec.norm, rgb_init(1, 1, 1)), 0.5));
    else
    {
        //ray의 방향벡터의 y 값을 기준으로 그라데이션을 주기 위한 계수.
        t = 0.5 * (ray->dir.y + 1.0);
        // (1-t) * 흰색 + t * 하늘색
        return (vt_plus(vt_multi(rgb_init(1, 1, 1), 1.0 - t), vt_multi(rgb_init(0.5, 0.7, 1.0), t)));
    }
}

// t_rgb    ray_color(t_ray *ray, t_sph *sph)
// {
//     double  t;
//     t_vt    norm;

//     t = hit_sphere(sph, ray);
//     if (t > 0.0)
//     {
//         //정규화 된 구 표면에서의 법선
//         norm = vt_unit(vt_minus(ray_at(ray, t), sph->center));
//         return (vt_multi(rgb_init(norm.x + 1, norm.y + 1, norm.z + 1), 0.5));
//     }
//     else
//     {
//         //ray의 방향벡터의 y 값을 기준으로 그라데이션을 주기 위한 계수.
//         t = 0.5 * (ray->dir.y + 1.0);
//         // (1-t) * 흰색 + t * 하늘색
//         return (vt_plus(vt_multi(rgb_init(1, 1, 1), 1.0 - t), vt_multi(rgb_init(0.5, 0.7, 1.0), t)));
//     }
// }