/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:18:48 by jrim              #+#    #+#             */
/*   Updated: 2022/09/12 20:55:07 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "structures.h"
# include "utils.h"

t_cnvs	canvas_init(int width, int height);
t_cam	camera_init(t_cnvs *canvas, t_pt orig);

t_obj	*object_init(t_obj_type type, void *element);
t_sph	*sphere_init(t_pt center, double radius);

#endif