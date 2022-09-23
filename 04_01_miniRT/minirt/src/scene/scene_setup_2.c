#include "minirt.h"

bool	ft_lights_setup(t_light *light, char *const *tbl)
{
	static const double	ratio_limit[2] = {0.0, 1.0};
	double				orig[3];
	double				ratio;

	if (light->initialized)
		return (ft_lights_error("light duplicate creation error."));
	if (!ft_check_strtod_iter(*++tbl, NULL, orig, 3))
		return (ft_lights_error("light format error (orig)."));
	if (!ft_check_strtod_iter(*++tbl, ratio_limit, &ratio, 1))
		return (ft_lights_error("light format error (ratio)."));
	if (NULL != *++tbl)
		return (ft_lights_error("light format error (more info)"));
	light->origin = point3(orig[0], orig[1], orig[2]);
	light->bright_ratio = ratio;
	light->initialized = true;
	light->light_color = color3(255, 255, 255);
	return (true);
}

bool	ft_ambient_setup(t_ambient *ambient, char *const *tbl)
{
	static const double	ratio_limit[2] = {0.0, 1.0};
	static const int	color_limit[2] = {0, 255};
	double				ratio;
	int					color[3];

	if (ambient->initialized)
		return (ft_lights_error("ambient duplicate creation error."));
	if (!ft_check_strtod_iter(*++tbl, ratio_limit, &ratio, 1))
		return (ft_lights_error("ambient format error (ratio)."));
	if (!ft_check_strtoi_iter(*++tbl, color_limit, color, 3))
		return (ft_lights_error("ambient format error (color)."));
	if (NULL != *++tbl)
		return (ft_lights_error("ambient format error (more info)"));
	ambient->ratio = ratio;
	ambient->color = color3(color[0], color[1], color[2]);
	ambient->initialized = true;
	ambient->color = vmult(ambient->color, ambient->ratio);
	return (true);
}
