/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:07:00 by jrim              #+#    #+#             */
/*   Updated: 2022/09/13 20:45:53 by jrim             ###   ########.fr       */
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

//---------------------- objects ----------------------//
typedef struct  s_sph
{
    t_pt    center;
    double  rad;
    double  rad_sq;
} t_sph;

typedef struct  s_plane
{
    t_pt    center;     // 평면의 어느 한 지점 
    t_vt    dir;        // 평면이 어떻게 기울어져 있는지
} t_plane;

typedef struct  s_cyl
{
    t_pt    center;      
    t_vt    dir;        
    double  diam;
    double  height;
} t_cyl;

typedef int     t_obj_type;
# define SPH 0
# define PLN 1
# define CYL 2

typedef struct  s_obj       // obj list
{
    t_obj_type  type;
    void        *element;   // 각 도혀의 데이터가 저장되는 곳
    void        *next;
    t_rgb       albedo;
}               t_obj;

//----------------------- ray -----------------------//
typedef struct  s_ray
{
    t_pt        orig;
    t_vt        dir;
}               t_ray;

//---------------------- hit ----------------------//
# define EPSILON 1e-6

typedef struct  s_hit
{
    t_pt        p;              //교점의 좌표
    t_vt        norm;           //교점에서의 법선
    double      t;              //광선의 원점과 교점 사이의 거리
    // tmin과 tmax의 값은 각각 0과 INFINITY로 오브젝트가 카메라의 뒤에 있거나(t < 0), 
    // 오브젝트가 카메라로부터 너무 멀 경우를 고려해주기 위함이다
    double      tmin;
    double      tmax;
    t_bool      front_face;
    t_rgb       albedo;
}               t_hit;

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

typedef struct  s_scene
{
    t_cnvs      cnvs;
    t_cam       cam;
    t_obj       *world;
    t_obj       *light;
    t_rgb       ambient; // 8.4에서 설명할 요소
    t_ray       ray;
    t_hit       rec;
}               t_scene;

//-------------------- lighting --------------------//
# define LIGHT_PT 1
# define LUMEN 3

typedef struct  s_light
{
    t_pt        orig;
    t_rgb       light_color;
    double      bright_ratio;
}               t_light;

#endif