/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:07:00 by jrim              #+#    #+#             */
/*   Updated: 2022/09/08 17:08:07 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_coord3 t_vt;
typedef struct s_coord3 t_pt;
typedef struct s_coord3 t_rgb;

struct s_coord3
{
    double	x;
    double	y;
    double	z;
};

typedef struct s_ray
{
    t_pt    orig;
    t_vt    dir;
} t_ray;

#endif