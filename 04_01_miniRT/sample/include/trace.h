/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:10:32 by jrim              #+#    #+#             */
/*   Updated: 2022/09/13 15:26:15 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACE_H
# define TRACE_H

# include "structures.h"
# include "utils.h"

t_ray		ray(t_pt orig, t_vt dir);
t_pt		ray_at(t_ray *ray, double t);
t_ray		ray_primary(t_cam *cam, double u, double v);

// t_rgb    	ray_color(t_ray *r);
t_rgb		ray_color(t_scene *scene);
// t_rgb		ray_color(t_ray *ray, t_obj *obj);

// double      hit_sphere(t_sph *sph, t_ray *ray);
t_hit		record_init(void);
t_bool      hit(t_obj *obj, t_ray *ray, t_hit *rec);
t_bool      hit_obj(t_obj *obj, t_ray *ray, t_hit *rec);
t_bool      hit_sphere(t_obj *obj, t_ray *ray, t_hit *rec);
// t_bool      hit_sphere(t_sph *sph, t_ray *ray, t_hit *rec);
void        set_face_normal(t_ray *ray, t_hit *rec);

t_rgb		phong_lighting(t_scene *scene);
t_vt		reflect(t_vt v, t_vt n);
t_rgb		point_light_get(t_scene *scene, t_light *light);

t_bool		in_shadow(t_obj *objs, t_ray ray, double light_len);

#endif