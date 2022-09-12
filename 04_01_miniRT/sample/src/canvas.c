/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:21:15 by jrim              #+#    #+#             */
/*   Updated: 2022/09/12 21:27:58 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

t_cnvs	canvas_init(int width, int height)
{
	t_cnvs	cnvs;

	cnvs.width = width;
	cnvs.height = height;
	cnvs.aspect_ratio = (double)width / (double)height;
	return (cnvs);
}

t_cam	camera_init(t_cnvs *cnvs, t_pt orig)
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
