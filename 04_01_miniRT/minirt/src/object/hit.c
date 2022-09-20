#include "minirt.h"

static bool	ft_spheres_hit(t_sp *spheres, int sp_size, t_ray *ray, t_hit *rec)
{
	int				i;
	t_hit	temp_rec;
	bool			hit_anything;

	i = 0;
	temp_rec = *rec;
	hit_anything = false;
	while (i < sp_size)
	{
		if (ft_sphere_hit(&(spheres[i]), ray, &temp_rec))
		{
			hit_anything = true;
			temp_rec.t_max = temp_rec.t;
			*rec = temp_rec;
		}
		i++;
	}
	return (hit_anything);
}

static bool	ft_planes_hit(t_pl *planes, int pl_size, t_ray *ray, t_hit *rec)
{
	int				i;
	t_hit	temp_rec;
	bool			hit_anything;

	i = 0;
	temp_rec = *rec;
	hit_anything = false;
	while (i < pl_size)
	{
		if (ft_plane_hit(&(planes[i]), ray, &temp_rec))
		{
			hit_anything = true;
			temp_rec.t_max = temp_rec.t;
			*rec = temp_rec;
		}
		i++;
	}
	return (hit_anything);
}

static bool	ft_cylinders_hit(t_cy *cylinders, int cy_size, t_ray *ray, t_hit *rec)
{
	int				i;
	t_hit	temp_rec;
	bool			hit_anything;

	i = 0;
	temp_rec = *rec;
	hit_anything = false;
	while (i < cy_size)
	{
		if (ft_cylinder_hit(&(cylinders[i]), ray, &temp_rec))
		{
			hit_anything = true;
			temp_rec.t_max = temp_rec.t;
			*rec = temp_rec;
		}
		i++;
	}
	return (hit_anything);
}

bool	ft_objects_hit(t_obj *objects, t_ray *ray, t_hit *rec)
{
	bool	hit_anything;

	hit_anything = false;
	if (ft_spheres_hit(objects->sp_arr, objects->sp_size, ray, rec))
		hit_anything = true;
	if (ft_planes_hit(objects->pl_arr, objects->pl_size, ray, rec))
		hit_anything = true;
	if (ft_cylinders_hit(objects->cy_arr, objects->cy_size, ray, rec))
		hit_anything = true;
	return (hit_anything);
}
