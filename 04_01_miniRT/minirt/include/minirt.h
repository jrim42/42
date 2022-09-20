#ifndef MINIRT_H
# define MINIRT_H

//------------------- main --------------------
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdbool.h>
# include <fcntl.h>
# include <errno.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"

# include "structs.h"
# include "mlx_hook.h"
# include "mlx_key.h"
# include "objects.h"
# include "ray.h"
# include "scene.h"
# include "utils.h"

//------------------- main --------------------
bool	ft_args_check(int argc, char *argv[]);

//------------------- graphic --------------------
/*
typedef struct s_graphic
{
	t_scene		scene;
	t_obj		objs;
}	t_graphic;
*/

void	ft_graphic_init(t_graphic *g);
void	ft_graphic_destroy(t_graphic *g);
bool	ft_graphic_error(t_graphic *g, const char *errmsg);
bool	ft_graphic_setup(t_graphic *g, const char *scenefile);
void	ft_graphic_render(t_graphic *g, t_img *img);
t_ray	ft_make_ray(t_graphic *g, double u, double v);

#endif