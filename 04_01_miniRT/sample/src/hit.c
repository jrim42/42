/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:51:54 by jrim              #+#    #+#             */
/*   Updated: 2022/09/14 17:49:17 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

t_hit	record_init(void)
{
    t_hit    rec;

    rec.tmin = EPSILON;
    rec.tmax = INFINITY;
    return (rec);
}

t_bool      hit(t_obj *obj, t_ray *ray, t_hit *rec)
{
    t_bool	hit_anything;
    t_hit	tmp_rec;

    tmp_rec = *rec; 		// tmp_rec의 tmin, tmax 값 초기화를 위해.
    hit_anything = FALSE;
    while(obj)
    {
        if (hit_obj(obj, ray, &tmp_rec))
        {
            hit_anything = TRUE;
            tmp_rec.tmax = tmp_rec.t;
            *rec = tmp_rec;
        }
        obj = obj->next;
    }
    return (hit_anything);
}

t_bool	hit_obj(t_obj *obj, t_ray *ray, t_hit *rec)
{
    t_bool  hit_result;

    hit_result = FALSE;
    if (obj->type == SPH)
        hit_result = hit_sphere(obj, ray, rec); //hit_sphere의 첫번째 인자도 t_sphere *에서 t_object *로 수정해주자.
	else if (obj->type == PLN)
		hit_result = hit_plane(obj, ray, rec);
	else if (obj->type == CYL)
		hit_result = hit_cylinder(obj, ray, rec);
    return (hit_result);
}

t_bool	hit_sphere(t_obj *obj, t_ray *ray, t_hit *rec)
{
	t_sph	*sph;
	t_vt	oc; //방향벡터로 나타낸 구의 중심.
	//a, b, c는 각각 t에 관한 2차 방정식의 계수
	double  a;
	double  half_b;
	double  c;
	double  discrim; //판별식
	double	sqrt_d;
	double	root;

	sph = (t_sph *)obj->element;
	oc = vt_minus(ray->orig, sph->center);
	
	a = vt_len_sq(ray->dir);
	half_b = vt_dot(oc, ray->dir);
	c = vt_len_sq(oc) - sph->rad_sq;
	discrim = half_b * half_b - a * c;
	
	if (discrim < 0)			// 판별식이 0보다 작다 == 실근이 존재하지 않는다.
		return (FALSE);
	sqrt_d = sqrt(discrim);
	root = (-half_b - sqrt_d) / a;
	if (root < rec->tmin || rec->tmax < root)
	{
		root = (-half_b + sqrt_d) / a;
		if (root < rec->tmin || rec->tmax < root)
			return (FALSE);
	}
	rec->t = root;
	rec->p = ray_at(ray, root);
	rec->norm = vt_div(vt_minus(rec->p, sph->center), sph->rad); // 정규화된 법선 벡터.
	rec->albedo = obj->albedo;
	set_face_normal(ray, rec); // rec의 법선벡터와 광선의 방향벡터를 비교해서 앞면인지 뒷면인지 t_bool 값으로 저장.
	return (TRUE);
}

t_bool	hit_plane(t_obj *obj, t_ray *ray, t_hit *rec)
{
	t_plane	*pln;
	double	numer;
	double	denom;
	double	root;

	pln = (t_plane *)obj->element;
	denom = vt_dot(ray->dir, pln->dir);
	if (fabs(denom) < EPSILON)
		return (FALSE);
	numer = vt_dot(vt_minus(pln->center, ray->orig), pln->dir);
	root = numer / denom;
	if (root < rec->tmin || root > rec->tmax)
		return (FALSE);
	rec->t = root;
	rec->p = ray_at(ray, root);
	rec->norm = pln->dir;
	set_face_normal(ray, rec);
	rec->albedo = obj->albedo;
	return (TRUE);
}

void    set_face_normal(t_ray *ray, t_hit *rec)
{
    // 광선의 방향벡터와 교점의 법선벡터의 내적이 음수이면 광선은 앞면(객체의)에 hit 한 것이다
    rec->front_face = vt_dot(ray->dir, rec->norm) < 0;
    // 광선의 앞면에 hit 면 그대로 아니면 법선을 반대로 뒤집는다. (항상 광선 방향벡터와 법선 벡터를 반대인 상태로 사용하기위해)
    rec->norm = (rec->front_face) ? rec->norm : vt_multi(rec->norm, -1);
}