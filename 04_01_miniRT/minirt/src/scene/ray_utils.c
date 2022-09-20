#include "minirt.h"

t_ray	ft_ray(const t_pt orig, const t_vt dir)
{
    t_ray	ray;

    ray.orig = orig;
    ray.dir = vunit(dir);
    return (ray);
}

t_pt	ft_ray_at(t_ray *ray, double t)
{
    t_pt	at;

    at = vplus(ray->orig, vmult(ray->dir, t));
    return (at);
}

t_ray	ft_ray_primary(const t_camera *cam, double v, double u)
{
    t_ray   ray;

    ray.orig = cam->orig;
    ray.dir = vunit(vminus(vplus(vplus(cam->l_bottom, vmult(cam->horizontal, u)), vmult(cam->vertical, v)), cam->orig));
    return (ray);
}

void	ft_ray_set_face_normal(t_ray *ray, t_hit *rec)
{
    rec->front_face = vdot(ray->dir, rec->normal) < 0;
	if (!(rec->front_face))
	    rec->normal = vmult(rec->normal, -1);
}