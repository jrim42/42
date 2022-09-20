#ifndef RAY_H
# define RAY_H

# include "structs.h"
# define EPSILON	1e-6
# define LUMEN		3

t_ray		ft_ray(const t_pt orig, const t_vt dir);
t_ray		ft_ray_primary(const t_camera *camera, double v, double u);
t_pt		ft_ray_at(t_ray *ray, double t);
void		ft_ray_set_face_normal(t_ray *ray, t_hit *rec);
t_cl		ft_ray_color(t_ray *ray, t_scene *scene, t_obj *objects);
// t_cl		dif_ref_light_get(t_scene *scene, t_hit *rec, t_ray *ray);
// t_cl		ft_ray_point_light(t_ray *ray, t_hit *rec, t_scene *scene, t_obj *objects);

t_cl		ft_point_light_get(t_ray *ray, t_hit *rec, t_scene *scene, t_obj *objects);

#endif