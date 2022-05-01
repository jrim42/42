/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _move.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:31:09 by jrim              #+#    #+#             */
/*   Updated: 2022/05/01 17:21:15 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_game *game, t_player *player, int dir);
int		_stuck_check(char **map, t_player *player, int dir);
void	_end_check(t_game *game, t_player *player);

void	move(t_game *game, t_player *player, int dir)
{
	if (_stuck_check(game->maps.coord, player, dir) == 1)
		return ;
	if (player->x_pos == player->x_end && player->y_pos == player->y_end)
		game->maps.coord[player->y_pos][player->x_pos] = 'E';
	else
		game->maps.coord[player->y_pos][player->x_pos] = '0';
	if (dir == DIR_UP)
		player->y_pos--;
	else if (dir == DIR_DW)
		player->y_pos++;
	else if (dir == DIR_LF)
		player->x_pos--;
	else if (dir == DIR_RT)
		player->x_pos++;
	player->step++;
	collec(game, player);
	msg_dfl("step : ", player->step, 0);
	game->maps.coord[player->y_pos][player->x_pos] = 'P';
	_end_check(game, player);
}

int	_stuck_check(char **map, t_player *player, int dir)
{
	int	x;
	int	y;

	x = player->x_pos;
	y = player->y_pos;
	if (dir == DIR_UP && map[y - 1][x] == '1')
		return (1);
	else if (dir == DIR_DW && map[y + 1][x] == '1')
		return (1);
	else if (dir == DIR_LF && map[y][x - 1] == '1')
		return (1);
	else if (dir == DIR_RT && map[y][x + 1] == '1')
		return (1);
	return (0);
}

void	_end_check(t_game *game, t_player *player)
{
	int	c_left;

	c_left = player->c_tot - player->c_cur;
	if (player->x_pos == player->x_end && player->y_pos == player->y_end)
	{
		if (c_left == 0)
			game->end = 1;
		else
			msg_dfl(0, c_left, " items are left! you can't leave!");
	}
}
