#include "minirt.h"

int	ft_cylinder_hit(t_cy *cyl, t_ray *ray, t_hit *rec)
{
	int		result;

	//--- cylinder set ----
	cyl->cap_top = vplus(cyl->point, vmult(cyl->normal, cyl->height / 2));
	cyl->cap_bot = vplus(cyl->point, vmult(cyl->normal, -(cyl->height / 2)));
	//----------------------
	result = 0;
	result += hit_cylinder_cap(cyl, ray, rec, CYL_CAP_TOP);
	result += hit_cylinder_cap(cyl, ray, rec, CYL_CAP_BOT);
	result += hit_cylinder_side(cyl, ray, rec);
	return (result);
}

bool	hit_cylinder_cap(t_cy *cyl, t_ray *ray, t_hit *rec, int mode)
{
	t_vt	cap_center;
	double	root;
	double	diameter;

	if (mode == CYL_CAP_TOP)
		cap_center = cyl->cap_top;
	else
		cap_center = cyl->cap_bot;
	if (!cyl_cap_root(cyl, ray, rec, &root))
		return (false);
	diameter = vlength(vminus(cap_center, ft_ray_at(ray, root)));
	if (fabs(cyl->radius) < fabs(diameter))
		return (false);
	rec->t = root;
	rec->p = ft_ray_at(ray, root);
	rec->t_max = rec->t;
	if (mode == CYL_CAP_TOP)
		rec->normal = cyl->normal;
	else
		rec->normal = vmult(cyl->normal, -1);
	ft_ray_set_face_normal(ray, rec);
	rec->albedo = cyl->albedo;
	return (true);
}

bool	cyl_cap_root(t_cy *cyl, t_ray *ray, t_hit *rec, double *root)
{
	t_vt	cap_center;
	double	denom;
	double	numer;

	if (*root == CYL_CAP_TOP)
		cap_center = cyl->cap_top;
	else
		cap_center = cyl->cap_bot;
	numer = vdot(vminus(cap_center, ray->orig), cyl->normal);
	denom = vdot(ray->dir, cyl->normal);
	*root = numer / denom;
	if (*root < rec->t_min || *root > rec->t_max)
		return (false);
	return (true);
}
