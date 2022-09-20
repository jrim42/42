#include "minirt.h"

static void	ft_write_color(t_img *img, int j, int i, const t_cl *clr)
{
	const int	bytes_per_pixel = img->bits_per_pixel / CHAR_BIT;
	int			trgb;
	char		*dst;

	dst = img->data + (j * img->line_length + i * bytes_per_pixel);
	trgb = ft_trgb(0, 255.999 * clr->x, 255.999 * clr->y, 255.999 * clr->z);
	*(unsigned int *)dst = trgb;
}

t_ray	ft_make_ray(t_graphic *g, double u, double v)
{
	t_ray		ray;
	t_camera	*cam;

	cam = &(g->scene.camera);
	ray.orig = g->scene.camera.orig;
	ray.dir = vunit(vminus(vplus(vplus(cam->l_bottom, \
		vmult(cam->horizontal, u)), vmult(cam->vertical, v)), cam->orig));
	return (ray);
}

void	ft_graphic_render(t_graphic *g, t_img *img)
{
	int			i;
	int			j;
	t_d_pair	dp;
	t_ray		ray;
	t_cl		color;

	i = -1;
	while (++i < g->scene.canvas.width)
	{
		j = -1;
		while (++j < g->scene.canvas.height)
		{
			dp.u = (double)i / (g->scene.canvas.width - 1);
			dp.v = (double)j / (g->scene.canvas.height - 1);
			ray = ft_make_ray(g, dp.u, dp.v);
			color = ft_ray_color(&ray, &(g->scene), &(g->objs));
			ft_write_color(img, g->scene.canvas.height - j - 1, i, &color);
		}
	}
}
