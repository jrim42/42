#include "minirt.h"

void	ft_minirt_hook_color(t_cl *color, int keycode, t_minirt	*rt)
{
	if (keycode == K_U)
		color->x += 0.1;
	if (keycode == K_I)
		color->x -= 0.1;
	if (keycode == K_O)
		color->y += 0.1;
	if (keycode == K_P)
		color->y -= 0.1;
	if (keycode == 33)
		color->z += 0.1;
	if (keycode == 30)
		color->z -= 0.1;
	if (30 <= keycode && keycode <= 35)
	{
		ft_color_range_check(color);
		rt->win.invalidate = true;
	}
}

void	ft_minirt_hook_albedo(t_cl *color, int keycode, t_minirt	*rt)
{
	if (keycode == 279)
		color->x += 0.1;
	if (keycode == 115)
		color->x -= 0.1;
	if (keycode == 117)
		color->y += 0.1;
	if (keycode == 119)
		color->y -= 0.1;
	if (keycode == 116)
		color->z += 0.1;
	if (keycode == 121)
		color->z -= 0.1;
	if (115 <= keycode && keycode < 279)
	{
		ft_color_range_check(color);
		rt->win.invalidate = true;
	}
}

static void	ft_minirt_hook_point2(t_pt *point, int keycode, t_minirt *rt)
{
	if (keycode == K_E)
	{
		point->x += 1;
		point->y += 1;
	}
	if (keycode == K_Z)
	{
		point->x -= 1;
		point->y -= 1;
	}
	if (keycode == K_C)
	{
		point->x += 1;
		point->y -= 1;
	}
	if (keycode == K_S)
		point->z -= 1;
	if (keycode == K_F)
		point->z += 1;
	if (keycode == K_E || keycode == K_Z || keycode == K_C || \
		keycode == K_S || keycode == K_F)
		rt->win.invalidate = true;
}

void	ft_minirt_hook_point(t_pt *point, int keycode, t_minirt	*rt)
{
	if (keycode == K_A)
		point->x -= 1;
	if (keycode == K_D)
		point->x += 1;
	if (keycode == K_W)
		point->y += 1;
	if (keycode == K_X)
		point->y -= 1;
	if (keycode == K_Q)
	{
		point->x -= 1;
		point->y += 1;
	}
	if (keycode == K_A || keycode == K_D || keycode == K_W || \
		keycode == K_Q || keycode == K_X)
		rt->win.invalidate = true;
	else
		ft_minirt_hook_point2(point, keycode, rt);
}
