#include "minirt.h"

bool	hit_cylinder_side(t_cy *cyl, t_ray *ray, t_hit *rec)
{
	double		root;

	if (!cyl_side_root(cyl, ray, rec, &root))
		return (false);
	if (!cyl_boundary(cyl, ft_ray_at(ray, root)))
		return (false);
	rec->t = root;
	rec->p = ft_ray_at(ray, root);
	rec->normal = cyl_norm(cyl, rec->p);
	ft_ray_set_face_normal(ray, rec);
	rec->albedo = cyl->albedo;
	return (true);
}

bool	cyl_side_root(t_cy *cyl, t_ray *ray, t_hit *rec, double *root)
{
	t_vt	to_center;
	double	a;
	double	half_b;
	double	c;
	double	discrim;

	to_center = vminus(ray->orig, cyl->point);
	a = vlength2(vcross(ray->dir, cyl->normal));
	half_b = vdot(\
		vcross(ray->dir, cyl->normal), vcross(to_center, cyl->normal));
	c = vlength2(vcross(to_center, cyl->normal)) - pow(cyl->diameter / 2, 2);
	discrim = half_b * half_b - a * c;
	if (discrim < 0)
		return (false);
	*root = (-half_b - sqrt(discrim)) / a;
	if (*root < rec->t_min || *root > rec->t_max)
	{
		*root = (-half_b + sqrt(discrim)) / a;
		if (*root < rec->t_min || *root > rec->t_max)
			return (false);
	}
	return (true);
}

bool	cyl_boundary(t_cy *cyl, t_vt at)
{
	double	hit_height;
	double	max_height;

	hit_height = vdot(vminus(at, cyl->point), cyl->normal);
	max_height = cyl->height / 2;
	if (fabs(hit_height) > max_height)
		return (false);
	return (true);
}

t_vt	cyl_norm(t_cy *cyl, t_vt at)
{
	t_vt	norm;
	t_vt	tmp;

	tmp = vminus(at, cyl->point);
	norm = vminus(tmp, vmult(cyl->normal, vdot(cyl->normal, tmp)));
	return (vunit(norm));
}
