#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdbool.h>
# include <stdlib.h>

typedef struct s_coord3	t_vt;
typedef struct s_coord3	t_pt;
typedef struct s_coord3	t_cl;
// typedef struct s_ray t_ray;
// typedef struct s_camera t_camera;
// typedef struct s_canvas t_canvas;
// typedef struct s_object t_object;
// typedef struct s_sphere t_sp;
// typedef struct s_plane t_pl;
// typedef struct s_light  t_light;
// typedef struct s_hit t_hit;
// typedef struct s_scene t_scene;

//-------------------ft_vt--------------------
struct s_coord3
{
	double	x;
	double	y;
	double	z;
};

typedef struct s_d_pair
{
	double	u;
	double	v;
}	t_d_pair;

//-------------------ft_structs--------------------
typedef struct s_img
{
	void	*img;
	char	*data;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_win
{
	void	*win;
	int		width;
	int		height;
	char	*title;
	bool	invalidate;
}	t_win;

typedef struct s_hook
{
	size_t	mode;
	int		sp_index;
	int		pl_index;
	int		cy_index;
}	t_hook;
//-------------------ft_camera--------------------
typedef struct s_canvas
{
	int		width;
	int		height;
	double	aspect_ratio;
}	t_canvas;

typedef struct s_camera
{
	t_pt	orig;
	t_vt		dir;
	int			fov;
	bool		initialized;
	t_vt		vertical;
	t_vt		horizontal;
	double		focal_length;
	double		viewport_width;
	double		viewport_height;
	t_pt	l_bottom;
}	t_camera;

//-------------------ft_lights--------------------
typedef struct s_light
{
	t_pt	origin;
	t_cl	light_color;
	double		bright_ratio;
	bool		initialized;
}	t_light;

typedef struct s_ambient
{
	t_cl	color;
	double		ratio;
	bool		initialized;
}	t_ambient;

//-------------------ft_scene--------------------
typedef struct s_scene
{
	t_canvas	canvas;
	t_camera	camera;
	t_light		lights;
	t_ambient	ambient;
}	t_scene;

//-------------------ft_cy--------------------
typedef struct s_cy
{
	t_cl	color;
	t_pt	point;
	t_vt		normal;
	double		height;
	double		diameter;
	double		radius;
	t_pt	cap_top;
	t_pt	cap_bot;
	t_cl	albedo;
}	t_cy;
//-------------------ft_pl--------------------
typedef struct s_plane
{
	t_cl	color;
	t_pt	point;
	t_vt		normal;
	t_cl	albedo;
}	t_pl;

//-------------------ft_sp--------------------
typedef struct s_sphere
{
	t_cl	color;
	t_pt	center;
	double		radius;
	double		diameter;
	t_cl	albedo;
}	t_sp;

//-------------------ft_object--------------------
typedef struct s_obj
{
	t_sp	*sp_arr;
	t_pl		*pl_arr;
	t_cy	*cy_arr;
	int			sp_size;
	int			pl_size;
	int			cy_size;
}	t_obj;

//-------------------ft_graphic--------------------
typedef struct s_graphic
{
	t_scene		scene;
	t_obj	objs;
}	t_graphic;
//-------------------ft_enum--------------------

enum e_limit
{
	LOWER_LIMIT,
	UPPER_LIMIT
};

//-------------------ft_minirt--------------------
typedef struct s_minirt
{
	void		*mlx;
	t_win		win;
	t_img		img;
	t_hook		hook;
	t_graphic	graphic;
}	t_minirt;

//-------------------ft_ray--------------------

typedef struct s_ray
{
	t_pt	orig;
	t_vt		dir;
}	t_ray;

typedef struct s_hit
{
	t_pt	p;
	t_vt		normal;
	double		t;
	double		t_min;
	double		t_max;
	bool		front_face;
	t_cl	albedo;
}	t_hit;

#endif
