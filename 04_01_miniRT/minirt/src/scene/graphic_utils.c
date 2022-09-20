#include "minirt.h"

void	ft_graphic_init(t_graphic *g)
{
	ft_memset(&(g->scene), 0, sizeof(t_scene));
	ft_memset(&(g->objs), 0, sizeof(t_obj));
}

void	ft_graphic_destroy(t_graphic *g)
{
	ft_objects_cleanup(&(g->objs));
}

bool	ft_graphic_error(t_graphic *g, const char *errmsg)
{
	if (errmsg)
	{
		ft_putendl_fd("\033[31;1mError\033[0m", STDERR_FILENO);
		ft_putstr_fd(" : ", STDERR_FILENO);
		ft_putendl_fd((char *)errmsg, STDERR_FILENO);
	}
	ft_graphic_destroy(g);
	return (false);
}
