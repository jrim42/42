/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:18:48 by jrim              #+#    #+#             */
/*   Updated: 2022/09/12 21:34:40 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "structures.h"
# include "utils.h"

t_cnvs	canvas_init(int width, int height);
t_cam	camera_init(t_cnvs *canvas, t_pt orig);

t_obj	*object_init(t_obj_type type, void *element, t_rgb albedo);
t_sph	*sphere_init(t_pt center, double radius);
t_light *light_point(t_pt orig, t_rgb color, double bright_ratio);

#endif