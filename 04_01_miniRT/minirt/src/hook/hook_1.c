#include "minirt.h"

void	ft_minirt_hook3(t_minirt *rt, int keycode)
{
	if (rt->hook.mode == 1)
		ft_minirt_hook_point(&rt->graphic.scene.camera.orig, keycode, rt);
	else if (rt->hook.mode == 2)
		ft_minirt_hook_point(&rt->graphic.scene.lights.origin, keycode, rt);
	else if (rt->hook.mode == 3)
	{	
		if (rt->graphic.objs.sp_size <= 0)
			return ;
		ft_minirt_hook_sp(&rt->graphic.objs.sp_arr[rt->hook.sp_index], \
			keycode, rt);
	}
	else if (rt->hook.mode == 4)
	{
		if (rt->graphic.objs.pl_size <= 0)
			return ;
		ft_minirt_hook_pl(&rt->graphic.objs.pl_arr[rt->hook.pl_index], \
			keycode, rt);
	}
	else if (rt->hook.mode == 5)
	{
		if (rt->graphic.objs.cy_size <= 0)
			return ;
		ft_minirt_hook_cy(\
			&rt->graphic.objs.cy_arr[rt->hook.cy_index], keycode, rt);
	}
}

void	ft_minirt_hook2(t_minirt *rt, int keycode)
{
	if (keycode == K_NUM_5)
	{
		if (rt->hook.mode == 5)
			ft_minirt_hook_indexing(&rt->hook.cy_index, \
				&rt->graphic.objs.cy_size);
		else
			rt->hook.mode = 5;
	}
	else
		ft_minirt_hook3(rt, keycode);
}

void	ft_minirt_hook(t_minirt *rt, int keycode)
{
	if (keycode == K_NUM_1)
		rt->hook.mode = 1;
	if (keycode == K_NUM_2)
		rt->hook.mode = 2;
	if (keycode == K_NUM_3)
	{
		if (rt->hook.mode == 3)
			ft_minirt_hook_indexing(&rt->hook.sp_index, \
				&rt->graphic.objs.sp_size);
		else
			rt->hook.mode = 3;
	}
	if (keycode == K_NUM_4)
	{
		if (rt->hook.mode == 4)
			ft_minirt_hook_indexing(&rt->hook.pl_index, \
				&rt->graphic.objs.pl_size);
		else
			rt->hook.mode = 4;
	}
	else
		ft_minirt_hook2(rt, keycode);
}
