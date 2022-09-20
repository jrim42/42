#include "minirt.h"

static void	ft_minirt_destroy(t_minirt *rt)
{
	if (rt->mlx && rt->img.img)
	{
		mlx_destroy_image(rt->mlx, rt->img.img);
		rt->img.img = NULL;
	}
	if (rt->mlx && rt->win.win)
	{
		mlx_clear_window(rt->mlx, rt->win.win);
		mlx_destroy_window(rt->mlx, rt->win.win);
		rt->win.win = NULL;
	}
	ft_graphic_destroy(&(rt->graphic));
}

void	ft_minirt_error(t_minirt *rt, const char *errmsg)
{
	if (errmsg)
	{
		ft_putendl_fd("\033[31;1mError\033[0m", STDERR_FILENO);
		ft_putstr_fd(" : ", STDERR_FILENO);
		ft_putendl_fd((char *)errmsg, STDERR_FILENO);
	}
	ft_minirt_destroy(rt);
	exit(EXIT_FAILURE);
}

void	ft_minirt_exit(t_minirt *rt)
{
	ft_putendl_fd("\033[32;1mSuccessfully terminated.\033[0m", STDOUT_FILENO);
	ft_minirt_destroy(rt);
	exit(EXIT_SUCCESS);
}
