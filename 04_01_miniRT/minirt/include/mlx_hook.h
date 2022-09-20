#ifndef MLX_HOOK_H
# define MLX_HOOK_H

# include "structs.h"

void	ft_minirt_create_window(t_minirt *rt, const char *scenefile);
void	ft_minirt_message_loop(t_minirt *rt);
void	ft_minirt_hook(t_minirt *rt, int keycode);

void	ft_minirt_error(t_minirt *rt, const char *errmsg);
void	ft_minirt_exit(t_minirt *rt);

void	ft_minirt_hook_camera(t_camera *cam, int keycode, t_minirt *rt);
void	ft_minirt_hook_sp(t_sp *sphere, int keycode, t_minirt *rt);
void	ft_minirt_hook_pl(t_pl *plane, int keycode, t_minirt *rt);
void	ft_minirt_hook_cy(t_cy *cylinder, int keycode, t_minirt *rt);

void	ft_minirt_hook_indexing(int *index, int *size);
void	ft_color_range_check(t_cl *color);
void    ft_normalized_vec_range_check(t_vt *normal);
void	ft_minirt_hook_color(t_cl *color, int keycode, t_minirt *rt);
void	ft_minirt_hook_albedo(t_cl *color, int keycode, t_minirt *rt);
void	ft_minirt_hook_point(t_pt *point, int keycode, t_minirt *rt);

#endif