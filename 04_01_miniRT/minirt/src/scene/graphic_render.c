#include "minirt.h"

static void	ft_write_color(t_img *img, int j, int i, const t_cl *clr)
{
	const int	bytes_per_pixel = img->bits_per_pixel / CHAR_BIT;
	int			trgb;
	char		*dst;

	dst = img->data + (j * img->line_length + i * bytes_per_pixel);
	trgb = ft_trgb(0, 255.999 * clr->x, 255.999 * clr->y, 255.999 * clr->z);
	*(unsigned int *)dst = trgb;
	// printf("%d %d %d\n", (int)(255.999 * clr->x),
    //                     (int)(255.999 * clr->y),
    //                     (int)(255.999 * clr->z));
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

	j = g->scene.canvas.height;
	while (--j >= 0)
	{
		i = -1;
		while (++i < g->scene.canvas.width)
		{
			dp.u = (double)i / (g->scene.canvas.width - 1);
			dp.v = (double)j / (g->scene.canvas.height - 1);
			// ray = ft_ray_primary(&g->scene.camera, dp.v, dp.u);
			ray = ft_make_ray(g, dp.u, dp.v);
			color = ft_ray_color(&ray, &(g->scene), &(g->objs));
			// printf("%d %d %d\n", (int)(255.999 * color.x),
            //             (int)(255.999 * color.y),
            //             (int)(255.999 * color.z));
			ft_write_color(img, g->scene.canvas.height - j - 1, i, &color);
		}
	}
}
