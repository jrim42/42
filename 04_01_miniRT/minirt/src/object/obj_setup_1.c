#include "minirt.h"

bool	ft_objects_setup(t_obj *objects, char *const *tbl)
{
	if (ft_is_sphere_type(tbl[0]))
	{
		if (!ft_sphere_setup(objects, tbl))
			return (false);
	}
	else if (ft_is_plane_type(tbl[0]))
	{
		if (!ft_plane_setup(objects, tbl))
			return (false);
	}
	else if (ft_is_cylinder_type(tbl[0]))
	{
		if (!ft_cylinder_setup(objects, tbl))
			return (false);
	}
	return (true);
}

static bool	ft_check_sphere_information(t_sp *sp, char *const *tbl)
{
	static const int	clr_limit[2] = {0, 255};
	double				center[3];
	double				diameter;
	int					color[3];

	if (!ft_check_strtod_iter(*++tbl, NULL, center, 3))
		return (ft_objects_error("sphere format error (center)."));
	if (!ft_check_strtod_iter(*++tbl, NULL, &diameter, 1))
		return (ft_objects_error("sphere format error (diameter)."));
	if (!ft_check_strtoi_iter(*++tbl, clr_limit, color, 3))
		return (ft_objects_error("sphere format error (color)."));
	if (NULL != *++tbl)
		return (ft_objects_error("sphere format error (more info)"));
	sp->center = point3(center[0], center[1], center[2]);
	sp->diameter = diameter;
	sp->radius = diameter / 2.0;
	sp->color = color3(color[0], color[1], color[2]);
	sp->albedo = sp->color;
	return (true);
}

bool	ft_sphere_setup(t_obj *objects, char *const *tbl)
{
	objects->sp_arr = ft_realloc(objects->sp_arr, \
			objects->sp_size + 1, sizeof(t_sp));
	if (!(objects->sp_arr))
		return (ft_objects_error("Can't allocate memory."));
	if (!ft_check_sphere_information(&objects->sp_arr[objects->sp_size], tbl))
		return (ft_objects_error(NULL));
	objects->sp_size++;
	return (true);
}