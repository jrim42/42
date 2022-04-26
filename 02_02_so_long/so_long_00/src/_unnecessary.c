/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _unnecessary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 19:39:59 by jrim              #+#    #+#             */
/*   Updated: 2022/04/26 19:40:21 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	_move_display(t_player *player, int dir);

void	_move_display(t_player *player, int dir)
{
	if (dir == DIR_UP)
		printf("up : (%d, %d)\n", player->x_pos, player->y_pos);
	else if (dir == DIR_DW)
		printf("down : (%d, %d)\n", player->x_pos, player->y_pos);
	else if (dir == DIR_LF)
		printf("left : (%d, %d)\n", player->x_pos, player->y_pos);
	else if (dir == DIR_RT)
		printf("right : (%d, %d)\n", player->x_pos, player->y_pos);
}
