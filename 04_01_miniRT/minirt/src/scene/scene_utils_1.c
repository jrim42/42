#include "minirt.h"

bool	ft_is_scene_type(const char *type)
{
	return (ft_is_camera_type(type) \
			|| ft_is_light_type(type) \
			|| ft_is_ambient_type(type));
}

bool	ft_check_scene_initialized(const t_scene *scene)
{
	if (!(scene->camera.initialized))
		return (false);
	if (!(scene->lights.initialized))
		return (false);
	if (!(scene->ambient.initialized))
		return (false);
	return (true);
}

bool	ft_scene_setup(t_scene *scene, char *const *tbl)
{
	if (ft_is_camera_type(tbl[0]) \
			&&!ft_camera_setup(&(scene->camera), &(scene->canvas), tbl))
		return (false);
	else if (ft_is_light_type(tbl[0]) \
			&& !ft_lights_setup(&(scene->lights), tbl))
		return (false);
	else if (ft_is_ambient_type(tbl[0]) \
			&& !ft_ambient_setup(&(scene->ambient), tbl))
		return (false);
	return (true);
}