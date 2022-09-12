/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:41:33 by jrim              #+#    #+#             */
/*   Updated: 2022/09/12 18:30:06 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

t_sph	sphere_init(t_pt center, double radius)
{
	t_sph sph;

	sph.center = center;
	sph.rad = radius;
	sph.rad_sq = radius * radius;
	return (sph);
}