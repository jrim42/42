#include "../include/miniRT.h"

#define CYL_CAP_TOP 0
#define CYL_CAP_BOT 1

t_bool	hit_cylinder_side(t_cyl *cyl, t_ray *ray, t_hit *rec);
t_bool	cyl_side_root(t_cyl *cyl, t_ray *ray, t_hit *rec, double *root);
t_bool	cyl_boundary(t_cyl *cyl, t_vt at);
t_vt	cyl_norm(t_cyl *cyl, t_vt at);
t_bool	hit_cylinder_cap(t_cyl *cyl, t_ray *ray, t_hit *rec, int mode);
t_bool	cyl_cap_root(t_cyl *cyl, t_ray *ray, t_hit *rec, double *root);

t_bool	hit_cylinder(t_obj *obj, t_ray *ray, t_hit *rec)
{
	int		result;
	t_cyl	*cyl;

	result = 0;
	cyl = obj->element;
	cyl->albedo = obj->albedo;
	result += hit_cylinder_cap(cyl, ray, rec, CYL_CAP_TOP);
	result += hit_cylinder_cap(cyl, ray, rec, CYL_CAP_BOT);
	result += hit_cylinder_side(cyl, ray, rec);
	return (result);
}

t_bool	hit_cylinder_side(t_cyl *cyl, t_ray *ray, t_hit *rec)
{
	double		root;

	if (!cyl_side_root(cyl, ray, rec, &root))
		return (FALSE);
	if (!cyl_boundary(cyl, ray_at(ray, root)))
		return (FALSE);
	rec->t= root;
	rec->p = ray_at(ray, root);
	rec->norm = cyl_norm(cyl, rec->p);
	set_face_normal(ray, rec);
	rec->albedo = cyl->albedo;
	return (TRUE);
}

t_bool	cyl_side_root(t_cyl *cyl, t_ray *ray, t_hit *rec, double *root)
{
	t_vt	to_center;
	double	a;
	double	half_b;
	double	c;
	double	discrim;

	to_center = vt_minus(ray->orig, cyl->point);
	a = vt_len_sq(vt_cross(ray->dir, cyl->normal));
	half_b = vt_dot(vt_cross(ray->dir, cyl->normal), vt_cross(to_center, cyl->normal));
	c = vt_len_sq(vt_cross(to_center, cyl->normal)) - pow(cyl->diameter / 2, 2);
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

t_bool	cyl_boundary(t_cyl *cyl, t_vt at)
{
	double	hit_height;
	double	max_height;

	hit_height = vt_dot(vt_minus(at, cyl->point), cyl->normal);
	max_height = cyl->height / 2;
	if (fabs(hit_height) > max_height)
		return (FALSE);
	return (TRUE);
}

t_vt	cyl_norm(t_cyl *cyl, t_vt at)
{
	t_vt	norm;
	t_vt	tmp;

	tmp = vt_minus(at, cyl->point);
	norm = vt_minus(tmp, vt_multi(cyl->normal, vt_dot(cyl->normal, tmp)));
	return (vt_unit(norm));
}


t_bool	hit_cylinder_cap(t_cyl *cyl, t_ray *ray, t_hit *rec, int mode)
{
	t_vt	cap_center;
	double	root;
	double	diameter;

	if (mode == CYL_CAP_TOP)
		cap_center = cyl->cap_top;
	else
		cap_center = cyl->cap_bot;
	if (!cyl_cap_root(cyl, ray, rec, &root))
		return (FALSE);
	diameter = vt_len(vt_minus(cap_center, ray_at(ray, root)));
	if (fabs(cyl->rad) < fabs(diameter))
		return (FALSE);
	rec->t = root;
	rec->p = ray_at(ray, root);
	rec->tmax = rec->t;
	if (mode == CYL_CAP_TOP)
		rec->norm = cyl->normal;
	else
		rec->norm = vt_multi(cyl->normal, -1);
	set_face_normal(ray, rec);
	rec->albedo = cyl->albedo;
	return (TRUE);
}

t_bool	cyl_cap_root(t_cyl *cyl, t_ray *ray, t_hit *rec, double *root)
{
	t_vt	cap_center;
	double	denom;
	double	numer;

	if (*root == CYL_CAP_TOP)
		cap_center = cyl->cap_top;
	else
		cap_center = cyl->cap_bot;
	numer = vt_dot(vt_minus(cap_center, ray->orig), cyl->normal);
	denom = vt_dot(ray->dir, cyl->normal);
	*root = numer / denom;
	if (*root < rec->tmin || *root > rec->tmax)
		return (FALSE);
	return (TRUE);
}
