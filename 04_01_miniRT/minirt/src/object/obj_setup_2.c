#include "minirt.h"

static bool	ft_check_plane_information(t_pl *pl, char *const *tbl)
{
	static const double	nor_limit[2] = {-1.0, 1.0};
	static const int	clr_limit[2] = {0, 255};
	double				point[3];
	double				normal[3];
	int					color[3];

	if (!ft_check_strtod_iter(*++tbl, NULL, point, 3))
		return (ft_objects_error("plane format error (point)."));
	if (!ft_check_strtod_iter(*++tbl, nor_limit, normal, 3))
		return (ft_objects_error("plane format error (normal)."));
	if (!ft_check_strtoi_iter(*++tbl, clr_limit, color, 3))
		return (ft_objects_error("plane format error (color)."));
	if (NULL != *++tbl)
		return (ft_objects_error("plane format error (more info)"));
	pl->point = point3(point[0], point[1], point[2]);
	pl->normal = vec3(normal[0], normal[1], normal[2]);
	pl->color = color3(color[0], color[1], color[2]);
	pl->albedo = pl->color;
	return (true);
}

bool	ft_plane_setup(t_obj *objects, char *const *tbl)
{
	objects->pl_arr = ft_realloc(objects->pl_arr, \
			objects->pl_size + 1, sizeof(t_pl));
	if (!(objects->pl_arr))
		return (ft_objects_error("Can't allocate memory."));
	if (!ft_check_plane_information(&objects->pl_arr[objects->pl_size], tbl))
		return (ft_objects_error(NULL));
	objects->pl_size++;
	return (true);
}

static bool	ft_check_cylinder_information1(t_cy *cy, char *const *tbl)
{
	static const double	nor_limit[2] = {-1.0, 1.0};
	double				point[3];
	double				normal[3];
	double				diameter;
	double				height;

	if (!ft_check_strtod_iter(*++tbl, NULL, point, 3))
		return (ft_objects_error("cylinder format error (point)."));
	if (!ft_check_strtod_iter(*++tbl, nor_limit, normal, 3))
		return (ft_objects_error("cylinder format error (normal)."));
	if (!ft_check_strtod_iter(*++tbl, NULL, &diameter, 1))
		return (ft_objects_error("cylinder format error (diameter)."));
	if (!ft_check_strtod_iter(*++tbl, NULL, &height, 1))
		return (ft_objects_error("cylinder format error (height)."));
	cy->point = point3(point[0], point[1], point[2]);
	cy->normal = vec3(normal[0], normal[1], normal[2]);
	cy->diameter = diameter;
	cy->radius = diameter / 2.0;
	cy->height = height;
	return (true);
}

static bool	ft_check_cylinder_information2(t_cy *cy, char *const *tbl)
{
	static const int	clr_limit[2] = {0, 255};
	int					color[3];

	if (!ft_check_strtoi_iter(*++tbl, clr_limit, color, 3))
		return (ft_objects_error("plane format error (color)."));
	if (NULL != *++tbl)
		return (ft_objects_error("cylinder format error (more info)"));
	cy->color = color3(color[0], color[1], color[2]);
	cy->cap_top = point3(0.0, 0.0, 0.0);
	cy->cap_bot = point3(0.0, 0.0, 0.0);
	cy->albedo = cy->color;
	return (true);
}

bool	ft_cylinder_setup(t_obj *objects, char *const *tbl)
{
	objects->cy_arr = ft_realloc(objects->cy_arr, \
			objects->cy_size + 1, sizeof(t_cy));
	if (!(objects->cy_arr))
		return (ft_objects_error("Can't allocate memory."));
	if (!ft_check_cylinder_information1(\
				&objects->cy_arr[objects->cy_size], tbl))
		return (ft_objects_error(NULL));
	if (!ft_check_cylinder_information2(\
				&objects->cy_arr[objects->cy_size], tbl + 4))
		return (ft_objects_error(NULL));
	objects->cy_size++;
	return (true);
}
