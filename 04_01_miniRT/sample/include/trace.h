/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:10:32 by jrim              #+#    #+#             */
/*   Updated: 2022/09/08 19:22:28 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACE_H
# define TRACE_H

# include "structures.h"
# include "utils.h"

t_ray	ray(t_pt orig, t_vt dir);
t_pt	ray_at(t_ray *ray, double t);
t_ray	ray_primary(t_cam *cam, double u, double v);
t_rgb	ray_color(t_ray *ray);

#endif