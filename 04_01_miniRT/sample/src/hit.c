/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:51:54 by jrim              #+#    #+#             */
/*   Updated: 2022/09/12 18:05:26 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/structures.h"
#include "../include/utils.h"

double      hit_sphere(t_sph *sp, t_ray *ray)
    {
        t_vt  oc; //방향벡터로 나타낸 구의 중심.
        //a, b, c는 각각 t에 관한 2차 방정식의 계수
        double  a;
        double  b;
        double  c;
        double  discrim; //판별식

        oc = vt_minus(ray->orig, sp->center);
        a = vt_dot(ray->dir, ray->dir);
        b = 2.0 * vt_dot(oc, ray->dir);
        c = vt_dot(oc, oc) - sp->rad_sq;
        discrim = b * b - 4 * a * c;

        // 판별식이 0보다 크다면 광선이 구를 hit한 것!
        if (discrim < 0) // 판별식이 0보다 작을 때 : 실근 없을 때,
        	return (-1.0);
    	else
    		return ((-b - sqrt(discrim)) / (2.0 * a)); // 두 근 중 작은 근
    }

// t_bool      hit_sphere(t_sph *sph, t_ray *ray, t_hit *rec)
// {
// 	t_vt	oc; //방향벡터로 나타낸 구의 중심.
// 	//a, b, c는 각각 t에 관한 2차 방정식의 계수
// 	double  a;
// 	double  half_b;
// 	double  c;
// 	double  discrim; //판별식
// 	double	sqrt_discrim;
// 	double	root;

// 	oc = vt_minus(ray->orig, sph->center);
// 	a = vt_len_sq(ray->dir);
// 	half_b = vt_dot(oc, ray->dir);
// 	c = vt_len_sq(oc) - sph->rad_sq;
// 	discrim = half_b * half_b - a * c;
	
	
// 	if (discrim < 0)			// 판별식이 0보다 작다 == 실근이 존재하지 않는다.
// 		return (FALSE);
// 	sqrt_discrim = sqrt(discrim);
// 	root = (-half_b - sqrt_discrim) / a;
// 	if (root < rec->tmin || rec->tmax < root)
// 	{
// 		root = (-half_b + sqrt_discrim) / a;
// 		if (root < rec->tmin || rec->tmax < root)
// 			return (FALSE);
// 	}
// 	// rec->t = root;
// 	// rec->p = ray_at(ray, root);
// 	// rec->norm = vt_divide(vt_minus(rec->p, sph->center), sph->rad); // 정규화된 법선 벡터.
// 	// set_face_normal(ray, rec); // rec의 법선벡터와 광선의 방향벡터를 비교해서 앞면인지 뒷면인지 t_bool 값으로 저장.
// 	return (TRUE);
// }

// void    set_face_normal(t_ray *ray, t_hit *rec)
// {
//     // 광선의 방향벡터와 교점의 법선벡터의 내적이 음수이면 광선은 앞면(객체의)에 hit 한 것이다
//     rec->front_face = vt_dot(ray->dir, rec->norm) < 0;
//     // 광선의 앞면에 hit 면 그대로 아니면 법선을 반대로 뒤집는다. (항상 광선 방향벡터와 법선 벡터를 반대인 상태로 사용하기위해)
//     rec->norm = (rec->front_face) ? rec->norm : vt_multi(rec->norm, -1);
// }