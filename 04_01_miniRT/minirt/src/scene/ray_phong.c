#include "minirt.h"

static t_vt	ft_reflect_dir(t_vt v, t_vt n)
{
	return (vminus(v, vmult(n, vdot(v, n) * 2)));
}

static bool	ft_is_in_shadow(t_obj *objs, t_ray ray, double light_len)
{
	t_hit	rec;

	rec.t_min = 0;
	rec.t_max = light_len;
	if (ft_objects_hit(objs, &ray, &rec))
		return (true);
	return (false);
}

static t_cl	ft_get_diffuse(t_hit *rec, t_light *light, t_vt light_dir)
{
	double	kd;
	t_cl	diffuse;

	kd = fmax(vdot(rec->normal, light_dir), 0.0);
    diffuse = vmult(light->light_color, kd);
	return (diffuse);
}

static t_cl	ft_get_specular(t_ray *ray, t_hit *rec, t_light *light, t_vt light_dir)
{
	t_vt	view_dir;
	t_vt	reflect_dir;
	double	ksn;
	double	ks;
	double	spec;
	t_cl	specular;
	
	view_dir = vunit(vmult(ray->dir, -1));
    reflect_dir = ft_reflect_dir(vmult(light_dir, -1), rec->normal);
	ksn = 64;
    ks = 0.5;
    spec = pow(fmax(vdot(view_dir, reflect_dir), 0.0), ksn);
    specular = vmult(vmult(light->light_color, ks), spec);
	return (specular);
}

t_cl		ft_point_light_get(t_ray *ray, t_hit *rec, t_scene *scene, t_obj *objects)
{
    t_cl	diffuse;
    t_vt	light_dir;
	t_cl	specular;
	double	brightness;
	double	light_len;
    t_ray	light_ray;

	light_dir = vminus(scene->lights.origin, rec->p);
    light_len = vlength(light_dir);
    light_ray = ft_ray(vplus(rec->p, vmult(rec->normal, EPSILON)), light_dir);
    if (ft_is_in_shadow(objects, light_ray, light_len))
        return (color3(0,0,0));
    light_dir = vunit(light_dir);
    diffuse = ft_get_diffuse(rec, &scene->lights, light_dir);
    specular = ft_get_specular(ray, rec, &scene->lights, light_dir);
	brightness = scene->lights.bright_ratio * LUMEN;
    return (vmult(vplus(vplus(scene->ambient.color, diffuse), specular), brightness));
}
