/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:41:33 by jrim              #+#    #+#             */
/*   Updated: 2022/09/12 15:58:26 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/structures.h"
#include "../include/scene.h"

t_sph	sphere_init(t_pt center, double radius)
{
	t_sph sph;

	sph.center = center;
	sph.rad = radius;
	sph.rad_sq = radius * radius;
	return (sph);
}