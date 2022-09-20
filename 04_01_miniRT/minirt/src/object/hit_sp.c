#include "minirt.h"

bool	ft_sphere_hit(const t_sp *sph, t_ray *ray, t_hit *rec)
{
	t_vt	oc;
	double  a;
	double  half_b;
	double  c;
	double  discrim;
	double	sqrt_d;
	double	root;

	oc = vminus(ray->orig, sph->center);
	a = vlength2(ray->dir);
	half_b = vdot(oc, ray->dir);
	c = vlength2(oc) - pow(sph->radius, 2);
	discrim = half_b * half_b - a * c;
	if (discrim < 0)
		return (false);
	sqrt_d = sqrt(discrim);
	root = (-half_b - sqrt_d) / a;
	if (root < rec->t_min || rec->t_max < root)
	{
		root = (-half_b + sqrt_d) / a;
		if (root < rec->t_min || rec->t_max < root)
			return (false);
	}
	rec->t = root;
	rec->p = ft_ray_at(ray, root);
	rec->normal = vdivide(vminus(rec->p, sph->center), sph->radius);
	rec->albedo = sph->albedo;
	ft_ray_set_face_normal(ray, rec);
	return (true);
}