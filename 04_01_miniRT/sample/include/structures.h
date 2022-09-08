/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:07:00 by jrim              #+#    #+#             */
/*   Updated: 2022/09/08 17:20:50 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

//---------------------- coords ----------------------//
struct s_coord3
{
    double	x;
    double	y;
    double	z;
};

typedef struct s_coord3 t_vt;
typedef struct s_coord3 t_pt;
typedef struct s_coord3 t_rgb;

//----------------------- ray -----------------------//
typedef struct  s_ray
{
    t_pt        orig;
    t_vt        dir;
}               t_ray;

//---------------------- scene ----------------------//
typedef struct  s_cam
{
    t_pt        orig;       // 카메라 원점(위치)
    double      vp_w;       // 뷰포트 가로길이
    double      vp_h;       // 뷰포트 세로길이
    t_vt        verti;        // 수직길이 벡터
    t_vt        hori;        // 수평길이 벡터
    double      focal_len;  // focal length
    t_pt        left_bot;   // 왼쪽 아래 코너점
} t_cam;

typedef struct  s_cnvs
{
    int         width;          //canvas width
    int         height;         //canvas height;
    double      aspect_ratio;   //종횡비
}               t_cnvs;

#endif