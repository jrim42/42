#include "minirt.h"

static void	ft_minirt_init(t_minirt *rt)
{
	rt->mlx = NULL;
	ft_memset(&(rt->win), 0, sizeof(t_win));
	ft_memset(&(rt->img), 0, sizeof(t_img));
	ft_memset(&(rt->hook), 0, sizeof(t_hook));
	ft_graphic_init(&(rt->graphic));
}

static void	ft_minirt_graphic_setup(t_minirt *rt, const char *scenefile)
{
	if (!ft_graphic_setup(&(rt->graphic), scenefile))
		ft_minirt_error(rt, NULL);
}

static void	ft_minirt_window_setup(t_minirt *rt)
{
	rt->win.width = rt->graphic.scene.canvas.width;
	rt->win.height = rt->graphic.scene.canvas.height;
	rt->win.title = "miniRT";
	rt->win.invalidate = true;
}

static void	ft_minirt_mlx_setup(t_minirt *rt)
{
	rt->mlx = mlx_init();
	if (!(rt->mlx))
		ft_minirt_error(rt, "Can't init mlx.");
	rt->win.win = mlx_new_window(rt->mlx, \
			rt->win.width, rt->win.height, rt->win.title);
	if (!(rt->win.win))
		ft_minirt_error(rt, "Can't get window surface.");
	rt->img.img = mlx_new_image(rt->mlx, rt->win.width, rt->win.height);
	if (!(rt->img.img))
		ft_minirt_error(rt, "Can't get image surface.");
	rt->img.data = mlx_get_data_addr(rt->img.img, \
			&rt->img.bits_per_pixel, &rt->img.line_length, &rt->img.endian);
	if (!(rt->img.data))
		ft_minirt_error(rt, "Can't get image data.");
}

void	ft_minirt_create_window(t_minirt *rt, const char *scenefile)
{
	ft_minirt_init(rt);
	ft_minirt_graphic_setup(rt, scenefile);
	ft_minirt_window_setup(rt);
	ft_minirt_mlx_setup(rt);
}
