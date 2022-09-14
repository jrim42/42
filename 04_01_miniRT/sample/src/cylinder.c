/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:16:21 by jrim              #+#    #+#             */
/*   Updated: 2022/09/14 20:35:18 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

int		cyl_bound(t_cyl *cyl, t_vt at);
t_vt	get_cyl_norm(t_cyl *cyl, t_vt at, double hit_height);
int		hit_cylinder_cap(t_obj *obj, t_ray *ray, t_hit *rec, double height);
t_bool	hit_cylinder_side(t_obj *obj, t_ray *ray, t_hit *rec);
t_bool	hit_cylinder(t_obj *obj, t_ray *ray, t_hit *rec);

int		cyl_bound(t_cyl *cyl, t_vt at)
{
	double	hit_height;
	double	max_height;

	hit_height = vt_dot(vt_minus(at, cyl->center), cyl->dir);
	max_height = cyl->height / 2;
	if (fabs(hit_height) > max_height)
		return (0);
	return (1);
}

t_vt	get_cyl_norm(t_cyl *cyl, t_vt at, double hit_height)
{
	// t_pt	hit_center;
	// t_vt	norm;

	// hit_center = vt_plus(cyl->center, vt_multi(cyl->dir, -hit_height));
	// norm = vt_minus(at, hit_center);
	// return (vt_unit(norm));

	t_vt	norm;
	t_vt	tmp;

	if (hit_height)
		;
	tmp = vt_minus(at, cyl->center);
	norm = vt_minus(tmp, vt_multi(cyl->dir, vt_dot(cyl->dir, tmp)));
	return (vt_unit(norm));
}

int		hit_cylinder_cap(t_obj *obj, t_ray *ray, t_hit *rec, double height)
{
	const t_cyl		*cyl = obj->element;
	const double	rad = cyl->diam / 2;
	const t_vt		cap_center = vt_plus(cyl->center, vt_multi(cyl->dir, height));
	const double	denom = vt_dot(ray->dir, cyl->dir);
	const double 	numer = vt_dot(vt_minus(cap_center, ray->orig), cyl->dir);
	const double	root = numer / denom;
    const double 	diameter = vt_len(vt_minus(cap_center, ray_at(ray, root)));

	if (fabs(rad) < fabs(diameter))
		return (0);
	if (root < rec->tmin || root > rec->tmax)
		return (0);
	rec->t = root;
	rec->p = ray_at(ray, root);
	rec->tmax = rec->t;
	if (0 < height)
		rec->norm = cyl->dir;
	else
		rec->norm = vt_minus_self(cyl->dir);
	set_face_normal(ray, rec);
	rec->albedo = obj->albedo;
	return (1);
}

t_bool	hit_cylinder_side(t_obj *obj, t_ray *ray, t_hit *rec)
{
	t_cyl	*cyl;
	t_vt	to_center;	// 방향벡터로 나타내는 원기둥의 아래쪽 cap의 center
	double	rad;		// cap의 반지름

	double	a;
	double	half_b;
	double	c;

	double	discrim;
	double	sqrt_d;
	double	root;
	double	hit_height;

	cyl = (t_cyl *)obj->element;
	rad = cyl->diam / 2;
	to_center = vt_minus(ray->orig, cyl->center);

	a = vt_len_sq(vt_cross(ray->dir, cyl->dir));
	half_b = vt_dot(vt_cross(ray->dir, cyl->dir), vt_cross(to_center, cyl->dir));
	c = vt_len_sq(vt_cross(to_center, cyl->dir)) - rad * rad;
	discrim = half_b * half_b - a * c;
	
	if (discrim < 0)
		return (FALSE);
	sqrt_d = sqrt(discrim);
	root = (-half_b - sqrt_d) / a;
	if (root < rec->tmin || root > rec->tmax)
	{
		root = (-half_b + sqrt_d) / a;
		if (root < rec->tmin || root > rec->tmax)
			return (FALSE);
	}	
	if (!(hit_height = cyl_bound(cyl, ray_at(ray, root))))
		return (FALSE);

	rec->t = root;
	rec->p = ray_at(ray, root);
	// rec->norm = cyl->dir;
	rec->norm = get_cyl_norm(cyl, rec->p, hit_height);
	set_face_normal(ray, rec);
	rec->albedo = obj->albedo;
	return (TRUE);
}

t_bool	hit_cylinder(t_obj *obj, t_ray *ray, t_hit *rec)
{
	const t_cyl	*cyl = obj->element;
	int			result;

	result = 0;
	result += hit_cylinder_cap(obj, ray, rec, cyl->height / 2);
	result += hit_cylinder_cap(obj, ray, rec, -(cyl->height / 2));
	result += hit_cylinder_side(obj, ray, rec);
	return (result);
}