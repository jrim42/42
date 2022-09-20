#include "minirt.h"

void	ft_minirt_hook_indexing(int *index, int *size)
{
	if (index >= size - 1)
		*index = 0;
	else
		*index += 1;
}

void	ft_color_range_check(t_cl *color)
{
	if (color->x >= 255)
		color->x = 255;
	if (color->x <= 0)
		color->x = 0;
	if (color->y >= 255)
		color->y = 255;
	if (color->y <= 0)
		color->y = 0;
	if (color->z >= 255)
		color->z = 255;
	if (color->z <= 0)
		color->z = 0;
}

void	ft_normalized_vec_range_check(t_vt *normal)
{
	if (normal->x >= 1)
		normal->x = 1;
	if (normal->x <= -1)
		normal->x = -1;
	if (normal->y >= 1)
		normal->y = 1;
	if (normal->y <= -1)
		normal->y = -1;
	if (normal->z >= 1)
		normal->z = 1;
	if (normal->z <= -1)
		normal->z = -1;
}