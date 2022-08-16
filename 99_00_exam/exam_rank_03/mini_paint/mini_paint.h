/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_paint.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 21:46:10 by jrim              #+#    #+#             */
/*   Updated: 2022/08/16 21:57:34 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_PAINT_H
# define MINI_PAINT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

typedef struct s_info
{
	int		w;
	int		h;
	char	background;
} t_info;

typedef struct s_circle
{
	char	type;
	float	x;
	float	y;
	float	r;
	char	color;
} t_circle;


#endif