#include "minirt.h"

static t_cl	ft_phong_lighting(
		t_scene *scene, t_ray *ray, t_hit *rec, t_obj *objects)
{
	t_cl	light_color;
	t_cl	ret;

	light_color = color3(0, 0, 0);
	light_color = vplus(light_color, ft_point_light_get(ray, rec, scene, objects));
	light_color = vplus(light_color, scene->ambient.color);
	ret = vmin(vmult_(light_color, rec->albedo), color3(1, 1, 1));
	// printf("%d %d %d\n", (int)(255.999 * ret.x),
    //                     (int)(255.999 * ret.y),
    //                     (int)(255.999 * ret.z));
	return (ret);
}

t_cl	ft_get_background_color(t_ray *ray)
{
	t_vt	unit_direction;
	t_cl	color;
	double		t;

	unit_direction = vunit(ray->dir);
	t = 0.5 * (unit_direction.y + 1.0);
	color.x = 1.0 - 0.5 * t;
	color.y = 1.0 - 0.3 * t;
	color.z = 1.0;
	// printf("%d %d %d\n", (int)(255.999 * color.x),
    //                     (int)(255.999 * color.y),
    //                     (int)(255.999 * color.z));
	return (color);
}

t_cl	ft_ray_color(t_ray *ray, t_scene *scene, t_obj *objs)
{
	t_hit	rec;

	rec.t_min = EPSILON;
	rec.t_max = INFINITY;
	if (ft_objects_hit(objs, ray, &rec))
		return (ft_phong_lighting(scene, ray, &rec, objs));
	else
		return (ft_get_background_color(ray));
}