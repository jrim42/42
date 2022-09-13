/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:28:35 by jrim              #+#    #+#             */
/*   Updated: 2022/09/13 18:52:46 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include "structures.h"

t_pt    pt_init(double x, double y, double z);
t_rgb   rgb_init(double r, double g, double b);

//---------------------- vector: basic ----------------------//
t_vt    vt_init(double x, double y, double z);
void    vt_set(t_vt *vec, double x, double y, double z);
double  vt_len(t_vt vec);
double  vt_len_sq(t_vt vec);
t_vt    vt_unit(t_vt vec);

//---------------------- vector: basic ----------------------//
t_vt    vt_plus(t_vt v1, t_vt v2);
t_vt    vt_plus_2(t_vt vec, double x, double y, double z);
t_vt    vt_minus(t_vt v1, t_vt v2);
t_vt    vt_minus_2(t_vt vec, double x, double y, double z);
t_vt    vt_minus_self(t_vt vec);
t_vt    vt_multi(t_vt vec, double t);
t_vt    vt_multi_2(t_vt v1, t_vt v2);
t_vt    vt_div(t_vt vec, double t);

//---------------------- vector: cal01 ---------------------//
double  vt_dot(t_vt vec, t_vt v2);
t_vt    vt_cross(t_vt v1, t_vt v2);
t_vt	vt_max(t_vt v1, t_vt v2);
t_vt	vt_min(t_vt v1, t_vt v2);

//------------------------ obj list ------------------------//
void	obj_add(t_obj **list, t_obj *new);
t_obj	*obj_last(t_obj *list);

#endif