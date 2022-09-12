/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:07:00 by jrim              #+#    #+#             */
/*   Updated: 2022/09/12 17:15:44 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# define FALSE 0
# define TRUE 1

typedef int t_bool;

//---------------------- coords ----------------------//
struct s_coord3
{
    double	x;
    double	y;
    double	z;
};

typedef struct s_coord3 t_vt;   // 벡터 구조체
typedef struct s_coord3 t_pt;   // 3차원 좌표계 구조체
typedef struct s_coord3 t_rgb;  // rgb 색상값 구조체

//---------------------- sphere ----------------------//
typedef struct  s_sph
{
    t_pt    center;
    double  rad;
    double  rad_sq;
} t_sph;

//----------------------- ray -----------------------//
typedef struct  s_ray
{
    t_pt        orig;
    t_vt        dir;
}               t_ray;

//---------------------- scene ----------------------//
typedef struct  s_cam
{
    t_pt        orig;           // 카메라 원점(위치)
    double      vp_w;           // 뷰포트 가로길이
    double      vp_h;           // 뷰포트 세로길이
    t_vt        verti;          // 수직길이 벡터
    t_vt        hori;           // 수평길이 벡터
    double      focal_len;      // focal length
    t_pt        left_bot;       // 왼쪽 아래 코너점
} t_cam;

typedef struct  s_cnvs
{
    int         width;          //canvas width
    int         height;         //canvas height;
    double      aspect_ratio;   //가로-세로 비율
}               t_cnvs;

//---------------------- hit ----------------------//
typedef struct  s_hit
{
    t_pt        p;              //교점의 좌표
    t_vt        norm;           //교점에서의 법선
    double      t;              //광선의 원점과 교점 사이의 거리
    double      tmin;
    double      tmax;
    t_bool      front_face;
}               t_hit;

#endif