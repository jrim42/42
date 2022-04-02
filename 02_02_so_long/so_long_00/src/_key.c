/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _key.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:06:36 by jrim              #+#    #+#             */
/*   Updated: 2022/04/02 17:58:10 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int     key_press(int key, t_game *game);
void    _up(t_game *game, t_player *player);
void    _down(t_game *game, t_player *player);
void    _left(t_game *game, t_player *player);
void    _right(t_game *game, t_player *player);


int     key_press(int key, t_game *game)
{
    if (key == KEY_EXIT)
		exit(0);
    else if (key == KEY_A || key == KEY_LF)
        _left(game, &game->player);
    else if (key == KEY_S || key == KEY_DW)
        _down(game, &game->player);
    else if (key == KEY_D || key == KEY_RT)
        _right(game, &game->player);
    else if (key == KEY_W || key == KEY_UP)
        _up(game, &game->player);
	return (0);
}

void    _up(t_game *game, t_player *player)
{
    if (!game)
        return ;
    player->y_pos++;
    player->step++;
	printf("up : (%d, %d)\n", player->x_pos, player->y_pos);
}

void    _down(t_game *game, t_player *player)
{
    if (!game)
        return ;
    player->y_pos--;
    player->step++;
	printf("down : (%d, %d)\n", player->x_pos, player->y_pos);
}

void    _left(t_game *game, t_player *player)
{
    if (!game)
        return ;
    player->x_pos--;
    player->step++;
	printf("left : (%d, %d)\n", player->x_pos, player->y_pos);
}

void    _right(t_game *game, t_player *player)
{
    if (!game)
        return ;
    player->x_pos++;
    player->step++;
	printf("right : (%d, %d)\n", player->x_pos, player->y_pos);
}