/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:41:33 by jrim              #+#    #+#             */
/*   Updated: 2022/09/12 20:47:27 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

t_obj    *object_init(t_obj_type type, void *element)
{
    t_obj    *new;

    if (!(new = (t_obj *)malloc(sizeof(t_obj))))
        return (NULL);
    new->type = type;
    new->element = element;
    new->next = NULL;
    return (new);
}

t_sph    *sphere_init(t_pt center, double radius)
{
    t_sph *sph;

    if(!(sph = (t_sph *)malloc(sizeof(t_sph))))
        return (NULL);
    sph->center = center;
    sph->rad = radius;
    sph->rad_sq = radius * radius;
    return (sph);
}