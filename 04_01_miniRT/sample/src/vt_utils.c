/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vt_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:08:31 by jrim              #+#    #+#             */
/*   Updated: 2022/09/08 19:23:32 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

t_pt    pt_init(double x, double y, double z)
{
    t_pt	point;

    point.x = x;
    point.y = y;
    point.z = z;
    return (point);
}

t_rgb   rgb_init(double r, double g, double b)
{
    t_rgb	color;

    color.x = r;
    color.y = g;
    color.z = b;
    return (color);
}

//---------------------- vector: basic ----------------------//

t_vt    vt_init(double x, double y, double z)
{
    t_vt	vec;

    vec.x = x;
    vec.y = y;
    vec.z = z;
    return (vec);
}

void    vt_set(t_vt *vec, double x, double y, double z)
{
    vec->x = x;
    vec->y = y;
    vec->z = z;
}

double  vt_len(t_vt vec)
{
    return (sqrt(vt_len_sq(vec)));
}

double  vt_len_sq(t_vt vec)
{
    return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

t_vt    vt_unit(t_vt vec)
{
    double len;
    
    len = vt_len(vec);
    if (len == 0)
    {
        printf("Error\n:Devider is 0");
        exit(0);
    }
    vec.x /= len;
    vec.y /= len;
    vec.z /= len;
    return (vec);
}

//---------------------- vector: cal01 ---------------------//

t_vt    vt_plus(t_vt v1, t_vt v2)
{
    v1.x += v2.x;
    v1.y += v2.y;
    v1.z += v2.z;
    return (v1);
}

t_vt    vt_plus_2(t_vt vec, double x, double y, double z)
{
    vec.x += x;
    vec.y += y;
    vec.z += z;
    return (vec);
}

t_vt    vt_minus(t_vt v1, t_vt v2)
{
    v1.x -= v2.x;
    v1.y -= v2.y;
    v1.z -= v2.z;
    return (v1);
}

t_vt    vt_minus_2(t_vt vec, double x, double y, double z)
{
    vec.x -= x;
    vec.y -= y;
    vec.z -= z;
    return (vec);
}

t_vt    vt_minus_self(t_vt vec)
{
    vec.x = -vec.x;
    vec.y = -vec.y;
    vec.z = -vec.z;
    return (vec);
}

t_vt    vt_multi(t_vt vec, double t)
{
    vec.x *= t;
    vec.y *= t;
    vec.z *= t;
    return (vec);
}

t_vt    vt_multi_2(t_vt v1, t_vt v2)
{
    v1.x *= v2.x;
    v1.y *= v2.y;
    v1.z *= v2.z;
    return (v1);
}

t_vt    vt_div(t_vt vec, double t)
{
    vec.x *= 1 / t;
    vec.y *= 1 / t;
    vec.z *= 1 / t;
    return (vec);
}

//---------------------- vector: cal02 ---------------------//

double  vt_dot(t_vt v1, t_vt v2)
{
    return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vt    vt_cross(t_vt v1, t_vt v2)
{
    t_vt    new;

    new.x = v1.y * v2.z - v1.z * v2.y;
    new.y = v1.z * v2.x - v1.x * v2.z;
    new.z = v1.x * v2.y - v1.y * v2.x;
    return (new);
}

t_vt    vt_max(t_vt v1, t_vt v2)
{
    if (v1.x < v2.x)
        v1.x = v2.x;
    if (v1.y < v2.y)
        v1.y = v2.y;
    if (v1.z < v2.z)
        v1.z = v2.z;
    return (v1);
}

t_vt    vt_min(t_vt v1, t_vt v2)
{
    if (v1.x > v2.x)
        v1.x = v2.x;
    if (v1.y > v2.y)
        v1.y = v2.y;
    if (v1.z > v2.z)
        v1.z = v2.z;
    return (v1);
}