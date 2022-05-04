/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _move.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:31:09 by jrim              #+#    #+#             */
/*   Updated: 2022/05/04 20:19:00 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_game *game, t_player *player, int new_dir);
int		_wall_check(char **map, t_player *player, int new_dir);
void	_alt_tile(t_player *player, char **map);
void	_alt_pos(t_player *player, int new_dir);
void	_end_check(t_game *game, t_player *player);

void	move(t_game *game, t_player *player, int new_dir)
{
	if (_wall_check(game->maps.coord, player, new_dir) == 1)
		return ;
	_alt_tile(player, game->maps.coord);
	_alt_pos(player, new_dir);
	player->step++;
	collec(game, player);
	msg_dfl("step : ", player->step, 0);
	game->maps.coord[player->y_pos][player->x_pos] = 'P';
	_end_check(game, player);
}

int	_wall_check(char **map, t_player *player, int new_dir)
{
	int	x;
	int	y;

	x = player->x_pos;
	y = player->y_pos;
	if (new_dir == DIR_UP && map[y - 1][x] == '1')
		return (1);
	else if (new_dir == DIR_DW && map[y + 1][x] == '1')
		return (1);
	else if (new_dir == DIR_LF && map[y][x - 1] == '1')
		return (1);
	else if (new_dir == DIR_RT && map[y][x + 1] == '1')
		return (1);
	return (0);
}

void	_alt_tile(t_player *player, char **map)
{
	//좌우에 따라 player 이미지 바꿔주기
	if (player->x_pos == player->x_end && player->y_pos == player->y_end)
		map[player->y_pos][player->x_pos] = 'E';
	else
		map[player->y_pos][player->x_pos] = '0';
}

void	_alt_pos(t_player *player, int new_dir)
{
	if (new_dir == DIR_UP)
		player->y_pos--;
	else if (new_dir == DIR_DW)
		player->y_pos++;
	else if (new_dir == DIR_LF)
		player->x_pos--;
	else if (new_dir == DIR_RT)
		player->x_pos++;
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
