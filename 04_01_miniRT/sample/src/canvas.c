/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:21:15 by jrim              #+#    #+#             */
/*   Updated: 2022/09/08 19:26:23 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/scene.h"

t_cnvs	canvas(int width, int height)
{
	t_cnvs	cnvs;

	cnvs.width = width;
	cnvs.height = height;
	cnvs.aspect_ratio = (double)width / (double)height;
	return (cnvs);
}

t_cam	camera(t_cnvs *cnvs, t_pt orig)
{
	t_cam	cam;
	double	focal_len;
	double	vp_h;

	vp_h = 2.0;
	focal_len = 1.0;
	cam.orig = orig;
	cam.vp_h = vp_h;
	cam.vp_w = vp_h * cnvs->aspect_ratio;
	cam.focal_len = focal_len;
	cam.hori = vt_init(cam.vp_w, 0, 0);
	cam.verti = vt_init(0, cam.vp_h, 0);
	// 왼쪽 아래 코너점 좌표, origin - horizontal / 2 - vertical / 2 - vec3(0,0,focal_length)
    cam.left_bot = vt_minus(vt_minus(vt_minus(cam.orig, vt_div(cam.hori, 2)),
                    vt_div(cam.verti, 2)), vt_init(0, 0, focal_len));
	return (cam);
}

t_ray	ray_primary(t_cam *cam, double u, double v)
{
    t_ray   ray;

    ray.orig = cam->orig;
    // left_bottom + u * horizontal + v * vertical - origin 의 단위 벡터.
    ray.dir = vt_unit(vt_minus(vt_plus(vt_plus(cam->left_bot, vt_multi(cam->hori, u)), vt_multi(cam->verti, v)), cam->orig));
    return (ray);
}

//광선이 최종적으로 얻게된 픽셀의 색상 값을 리턴.
t_rgb    ray_color(t_ray *r)
{
    double  t;

    t = 0.5 * (r->dir.y + 1.0);
    // (1-t) * 흰색 + t * 하늘색
    return (vt_plus(vt_multi(rgb_init(1, 1, 1), 1.0 - t), vt_multi(rgb_init(0.5, 0.7, 1.0), t)));
}
