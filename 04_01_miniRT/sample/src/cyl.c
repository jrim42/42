/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:22:43 by jrim              #+#    #+#             */
/*   Updated: 2022/09/15 16:01:23 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

t_bool	hit_cylinder(t_obj *obj, t_ray *ray, t_hit *rec);
t_bool	hit_cylinder_cap(t_obj *obj, t_ray *ray, t_hit *rec, double half_h);
t_bool	hit_cylinder_side(t_obj *obj, t_ray *ray, t_hit *rec);
t_bool	cyl_side_root(t_cyl *cyl, t_ray *ray, t_hit *rec, double *root);
t_bool	cyl_bound(t_cyl *cyl, t_vt at);
t_vt	cyl_norm(t_cyl *cyl, t_vt at);

t_bool	hit_cylinder(t_obj *obj, t_ray *ray, t_hit *rec)
{
	t_cyl	*cyl;
	int		result;

	cyl = obj->element;
	result = 0;
	result += hit_cylinder_cap(obj, ray, rec, cyl->height / 2);
	result += hit_cylinder_cap(obj, ray, rec, -(cyl->height / 2));
	result += hit_cylinder_side(obj, ray, rec);
	return (result);
}

t_bool	hit_cylinder_cap(t_obj *obj, t_ray *ray, t_hit *rec, double half_h)
{
	// 각 오브젝트 구조체에 albedo 담을 예정
	// 그러면 함수 호출할 때 t_cyl로 받아오면 됨.
	t_cyl	*cyl;
	t_vt	cap_center;
	double	cap_rad;
	double	root;
    double 	diameter;

	cyl = obj->element;
	
	cap_center = vt_plus(cyl->center, vt_multi(cyl->dir, half_h));
	cap_rad = cyl->diam / 2;
	// numer = vt_dot(vt_minus(cap_center, ray->orig), cyl->dir);
	// denom = vt_dot(ray->dir, cyl->dir);
	// root = numer / denom;
	root = vt_dot(vt_minus(cap_center, ray->orig), cyl->dir) /
			vt_dot(ray->dir, cyl->dir);
			
	diameter = vt_len(vt_minus(cap_center, ray_at(ray, root)));
	
	if (fabs(cap_rad) < fabs(diameter))
		return (FALSE);
	if (root < rec->tmin || root > rec->tmax)
		return (FALSE);
		
	rec->t = root;
	rec->p = ray_at(ray, root);
	rec->tmax = rec->t;
	if (0 < half_h)
		rec->norm = cyl->dir;
	else
		rec->norm = vt_minus_self(cyl->dir);
	set_face_normal(ray, rec);
	rec->albedo = obj->albedo;
	return (TRUE);
}

t_bool	hit_cylinder_side(t_obj *obj, t_ray *ray, t_hit *rec)
{
	t_cyl	*cyl;
	double	root;

	cyl = obj->element;
	if (!cyl_side_root(cyl, ray, rec, &root))
		return (FALSE);
	if (!cyl_bound(cyl, ray_at(ray, root)))
		return (FALSE);
	rec->t = root;
	rec->p = ray_at(ray, root);
	rec->norm = cyl_norm(cyl, rec->p);
	set_face_normal(ray, rec);
	rec->albedo = obj->albedo;
	return (TRUE);
}

t_bool	cyl_side_root(t_cyl *cyl, t_ray *ray, t_hit *rec, double *root)
{	
	t_vt	bottom_center;	// 방향벡터로 나타내는 원기둥의 아래쪽 cap의 center
	double	a;
	double	half_b;
	double	c;
	double	discrim;

	bottom_center = vt_minus(ray->orig, cyl->center);
	a = vt_len_sq(vt_cross(ray->dir, cyl->dir));
	half_b = vt_dot(vt_cross(ray->dir, cyl->dir), vt_cross(bottom_center, cyl->dir));
	c = vt_len_sq(vt_cross(bottom_center, cyl->dir)) - pow(cyl->diam / 2, 2);
	discrim = half_b * half_b - a * c;
	if (discrim < 0)
		return (FALSE);
	*root = (-half_b - sqrt(discrim)) / a;
	if (*root < rec->tmin || *root > rec->tmax)
	{
		*root = (-half_b + sqrt(discrim)) / a;
		if (*root < rec->tmin || *root > rec->tmax)
			return (FALSE);
	}	
	return (TRUE);
}

t_bool	cyl_bound(t_cyl *cyl, t_vt at)
{
	double	hit_height;
	double	max_height;

	hit_height = vt_dot(vt_minus(at, cyl->center), cyl->dir);
	max_height = cyl->height / 2;
	if (fabs(hit_height) > max_height)
		return (FALSE);
	return (TRUE);
}

t_vt	cyl_norm(t_cyl *cyl, t_vt at)
{
	t_vt	norm;
	t_vt	tmp;

	tmp = vt_minus(at, cyl->center);
	norm = vt_minus(tmp, vt_multi(cyl->dir, vt_dot(cyl->dir, tmp)));
	return (vt_unit(norm));
}