/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:11:18 by jrim              #+#    #+#             */
/*   Updated: 2022/09/08 17:12:59 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/trace.h"

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