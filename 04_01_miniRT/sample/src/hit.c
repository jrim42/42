/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:51:54 by jrim              #+#    #+#             */
/*   Updated: 2022/09/12 16:02:05 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/structures.h"
#include "../include/utils.h"

double      hit_sphere(t_sph *sph, t_ray *ray)
{
	t_vt	oc; //방향벡터로 나타낸 구의 중심.
	//a, b, c는 각각 t에 관한 2차 방정식의 계수
	double  a;
	double  b;
	double  c;
	double  discrim; //판별식

	oc = vt_minus(ray->orig, sph->center);
	a = vt_dot(ray->dir, ray->dir);
	b = 2.0 * vt_dot(oc, ray->dir);
	c = vt_dot(oc, oc) - sph->rad_sq;
	discrim = b * b - 4 * a * c;
	if (discrim < 0)			// 판별식이 0보다 작다 == 실근이 존재하지 않는다.
		return (-1.0);
	else						// 그 외의 경우 두 근 중 작은 쪽을 return해준다.
		return ((-b - sqrt(discrim)) / (2.0 * a));	
}
