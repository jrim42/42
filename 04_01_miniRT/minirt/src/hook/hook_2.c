#include "minirt.h"

static void	ft_minirt_hook_vec(t_vt *vec, int keycode, t_minirt *rt)
{
	if (keycode == K_N)
		vec->x -= 0.1;
	if (keycode == K_M)
		vec->x += 0.1;
	if (keycode == 43)
		vec->y -= 0.1;
	if (keycode == 47)
		vec->y += 0.1;
	if (keycode == 44)
		vec->z -= 0.1;
	if (keycode == 39)
		vec->z += 0.1;
	if ((43 <= keycode && keycode <= 47) || keycode == 39)
	{
		ft_normalized_vec_range_check(vec);
		rt->win.invalidate = true;
	}
	else
		return ;
}

void	ft_minirt_hook_camera(t_camera *cam, int keycode, t_minirt	*rt)
{
	if (keycode == K_J)
	{
		if (cam->fov > 0)
			cam->fov -= 1;
		else
			return ;
	}
	if (keycode == K_K)
	{
		if (cam->fov < 180)
			cam->fov += 1;
		else
			return ;
	}
	if ((43 <= keycode && keycode <= 47) || keycode == 39)
		ft_minirt_hook_vec(&cam->dir, keycode, rt);
	if (keycode == K_J || keycode == K_K)
		rt->win.invalidate = true;
	if (0 <= keycode && keycode < 15)
		ft_minirt_hook_point(&cam->orig, keycode, rt);
	else
		return ;
}

void	ft_minirt_hook_sp(t_sp *sp, int keycode, t_minirt *rt)
{
	if (keycode == K_J)
	{
		if (sp->radius == 1)
			return ;
		else
			sp->radius -= 1;
	}
	if (keycode == K_K)
		sp->radius += 1;
	if (keycode == K_J || keycode == K_K)
		rt->win.invalidate = true;
	if (0 <= keycode && keycode < 15)
		ft_minirt_hook_point(&sp->center, keycode, rt);
	if (115 <= keycode && keycode < 279)
		ft_minirt_hook_albedo(&sp->albedo, keycode, rt);
	else
		ft_minirt_hook_color(&sp->color, keycode, rt);
}

void	ft_minirt_hook_pl(t_pl *pl, int keycode, t_minirt *rt)
{
	if (keycode == K_J)
		pl->normal.x -= 0.1;
	if (keycode == K_K)
		pl->normal.x += 0.1;
	if (keycode == K_L)
		pl->normal.y -= 0.1;
	if (keycode == 41)
		pl->normal.y += 0.1;
	if (keycode == K_N)
		pl->normal.z -= 0.1;
	if (keycode == K_M)
		pl->normal.z += 0.1;
	if ((37 <= keycode && keycode <= 40) || keycode == K_N || keycode == K_M)
	{
		ft_normalized_vec_range_check(&pl->normal);
		rt->win.invalidate = true;
	}
	if (0 <= keycode && keycode < 15)
		ft_minirt_hook_point(&pl->point, keycode, rt);
	if (115 <= keycode && keycode < 279)
		ft_minirt_hook_albedo(&pl->albedo, keycode, rt);
	else
		ft_minirt_hook_color(&pl->color, keycode, rt);
}

void	ft_minirt_hook_cy(t_cy *cy, int keycode, t_minirt *rt)
{
	if (keycode == K_J)
	{	
		if (cy->diameter == 1)
			return ;
		else
			cy->diameter -= 1;
	}
	if (keycode == K_K)
		cy->diameter += 1;
	if (keycode == K_J || keycode == K_K)
		rt->win.invalidate = true;
	if (0 <= keycode && keycode < 15)
		ft_minirt_hook_point(&cy->point, keycode, rt);
	if (115 <= keycode && keycode < 279)
		ft_minirt_hook_albedo(&cy->albedo, keycode, rt);
	if ((43 <= keycode && keycode <= 47) || keycode == 39)
		ft_minirt_hook_vec(&cy->normal, keycode, rt);
	else
		ft_minirt_hook_color(&cy->color, keycode, rt);
}
