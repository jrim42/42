#ifndef SCENE_H
# define SCENE_H

# include "structs.h"

//------------------- graphic --------------------
void	ft_graphic_init(t_graphic *g);
void	ft_graphic_destroy(t_graphic *g);
bool	ft_graphic_error(t_graphic *g, const char *errmsg);
bool	ft_graphic_setup(t_graphic *g, const char *scenefile);
void	ft_graphic_render(t_graphic *g, t_img *img);
t_ray	ft_make_ray(t_graphic *g, double u, double v);

//------------------- scene --------------------
bool	ft_is_scene_type(const char *type);
bool	ft_check_scene_initialized(const t_scene *scene);
bool	ft_scene_setup(t_scene *scene, char *const *tbl);
t_cl	ft_get_background_color(t_ray *ray);

//------------------- camera --------------------
# define FOV_LIMIT	180
# define PI			3.14159265359

bool	ft_is_camera_type(const char *type);
bool	ft_camera_error(const char *errmsg);

bool	ft_camera_setup(t_camera *camera, t_canvas *canvas, char *const *tbl);
t_vt	dir_setup(t_vt dir);
double	ft_fov2rad(int FOV);

//------------------- lights --------------------
bool	ft_is_light_type(const char *type);
bool	ft_is_ambient_type(const char *type);
bool	ft_lights_error(const char *errmsg);

bool	ft_lights_setup(t_light *lights, char *const *tbl);
bool	ft_ambient_setup(t_ambient *ambient, char *const *tbl);

#endif