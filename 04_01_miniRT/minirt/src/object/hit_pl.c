#include "minirt.h"

bool	ft_plane_hit(const t_pl *pl, t_ray *ray, t_hit *rec)
{
	double	numer;
	double	denom;
	double	root;

	denom = vdot(ray->dir, pl->normal);
	if (fabs(denom) < EPSILON)
		return (false);
	numer = vdot(vminus(pl->point, ray->orig), pl->normal);
	root = numer / denom;
	if (root < rec->t_min || root > rec->t_max)
		return (false);
	rec->t = root;
	rec->p = ft_ray_at(ray, root);
	rec->normal = pl->normal;
	ft_ray_set_face_normal(ray, rec);
	rec->albedo = pl->albedo;
	return (true);
}