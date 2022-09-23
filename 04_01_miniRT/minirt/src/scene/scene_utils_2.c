#include "minirt.h"

bool	ft_is_light_type(const char *type)
{
	return (!ft_strcmp(type, "L"));
}

bool	ft_is_ambient_type(const char *type)
{
	return (!ft_strcmp(type, "A"));
}

bool	ft_lights_error(const char *errmsg)
{
	if (errmsg)
	{
		ft_putendl_fd("\033[31;1mError\033[0m", STDERR_FILENO);
		ft_putstr_fd(" : ", STDERR_FILENO);
		ft_putendl_fd((char *)errmsg, STDERR_FILENO);
	}
	return (false);
}

bool	ft_is_camera_type(const char *type)
{
	return (!ft_strcmp(type, "C"));
}

bool	ft_camera_error(const char *errmsg)
{
	if (errmsg)
	{
		ft_putendl_fd("\033[31;1mError\033[0m", STDERR_FILENO);
		ft_putstr_fd(" : ", STDERR_FILENO);
		ft_putendl_fd((char *)errmsg, STDERR_FILENO);
	}
	return (false);
}