#ifndef OBJECTS_H
# define OBJECTS_H

# include "structs.h"

//------------------- object --------------------
bool	ft_is_object_type(const char *type);
bool	ft_check_objects_initialized(const t_obj *objects);
void	ft_objects_cleanup(t_obj *objects);
bool	ft_objects_error(const char *errmsg);
bool	ft_objects_setup(t_obj *objects, char *const *tbl);
bool	ft_objects_hit(t_obj *objects, t_ray *ray, t_hit *rec);

//------------------- sphere --------------------
bool	ft_is_sphere_type(const char *type);
bool	ft_sphere_setup(t_obj *objects, char *const *tbl);
bool	ft_sphere_hit(const t_sp *data, t_ray *ray, t_hit *rec);

//------------------- plane --------------------
bool	ft_is_plane_type(const char *type);
bool	ft_plane_setup(t_obj *objects, char *const *tbl);
bool	ft_plane_hit(const t_pl *data, t_ray *ray, t_hit *rec);

//------------------- cylinder --------------------
# define CYL_CAP_TOP 0
# define CYL_CAP_BOT 1

bool	ft_is_cylinder_type(const char *type);
bool	ft_cylinder_setup(t_obj *objects, char *const *tbl);
int		ft_cylinder_hit(t_cy*cy, t_ray *ray, t_hit *rec);

bool	hit_cylinder(t_cy*obj, t_ray *ray, t_hit *rec);
bool	hit_cylinder_cap(t_cy*cyl, t_ray *ray, t_hit *rec, int mode);
bool	cyl_cap_root(t_cy*cyl, t_ray *ray, t_hit *rec, double *root);
bool	hit_cylinder_side(t_cy*obj, t_ray *ray, t_hit *rec);
bool	cyl_side_root(t_cy*cyl, t_ray *ray, t_hit *rec, double *root);
bool	cyl_boundary(t_cy*cyl, t_vt at);
t_vt	cyl_norm(t_cy*cyl, t_vt at);

#endif
