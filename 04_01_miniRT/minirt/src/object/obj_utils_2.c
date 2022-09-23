#include "minirt.h"

bool	ft_is_sphere_type(const char *type)
{
	return (!ft_strcmp(type, "sp"));
}

bool	ft_is_plane_type(const char *type)
{
	return (!ft_strcmp(type, "pl"));
}

bool	ft_is_cylinder_type(const char *type)
{
	return (!ft_strcmp(type, "cy"));
}
