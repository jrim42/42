/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_paint.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 22:41:54 by jrim              #+#    #+#             */
/*   Updated: 2022/08/16 22:42:51 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MICRO_PAINT_H
# define MICRO_PAINT_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

typedef struct s_info
{
	int		w;
	int		h;
	char	background;
} t_info;

typedef struct s_rect
{
	char	type;
	float	x;
	float	y;
	float	w;
	float	h;
	char	color;
} t_rect;

#endif