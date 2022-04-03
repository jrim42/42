/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _move.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:31:09 by jrim              #+#    #+#             */
/*   Updated: 2022/04/03 14:45:22 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    _move(t_game *game, t_player *player, int dir);
int     _move_stuck(char **map, t_player *player, int dir);
void    _move_display(t_player *player, int dir);

void    _move(t_game *game, t_player *player, int dir)
{
    if (_move_stuck(game->maps.coord, player, dir) == 1)
        return ;
    if (dir == DIR_UP)
        player->y_pos--;
    else if (dir == DIR_DW)
        player->y_pos++;
    else if (dir == DIR_LF)
        player->x_pos--;
    else if (dir == DIR_RT)
        player->x_pos++;
    player->step++;
    ft_put_img64(game, player->p_img.ptr, player->x_pos, player->y_pos);
    _move_display(player, dir);
    if (player->x_pos == player->x_end && player->y_pos == player->y_end)
        game->end = 1;
}

int     _move_stuck(char **map, t_player *player, int dir)
{
    int x;
    int y;

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

void    _move_display(t_player *player, int dir)
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