#include "minirt.h"

bool	ft_is_object_type(const char *type)
{
	return (ft_is_sphere_type(type) \
			|| ft_is_plane_type(type) \
			|| ft_is_cylinder_type(type));
}

bool	ft_check_objects_initialized(const t_obj *objects)
{
	return (objects->sp_size \
			|| objects->pl_size \
			|| objects->cy_size);
}

void	ft_objects_cleanup(t_obj *objects)
{
	if (objects->sp_arr)
	{
		free(objects->sp_arr);
		objects->sp_arr = NULL;
	}
	if (objects->pl_arr)
	{
		free(objects->pl_arr);
		objects->pl_arr = NULL;
	}
	if (objects->cy_arr)
	{
		free(objects->cy_arr);
		objects->cy_arr = NULL;
	}
}

bool	ft_objects_error(const char *errmsg)
{
	if (errmsg)
	{
		ft_putendl_fd("\033[31;1mError\033[0m", STDERR_FILENO);
		ft_putstr_fd(" : ", STDERR_FILENO);
		ft_putendl_fd((char *)errmsg, STDERR_FILENO);
	}
	return (false);
}
