/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _collec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 18:33:14 by jrim              #+#    #+#             */
/*   Updated: 2022/04/09 19:17:56 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    _collec(t_game *game, t_player *player);
void    _collec_display(t_player *player);
void    _collec_c2t(t_game *game, int c_pos);

void    _collec(t_game *game, t_player *player)
{
    int     p_pos;
    int     *c_pos;
    int     idx;

    p_pos = player->x_pos * 100 + player->y_pos;
    c_pos = game->maps.c_pos;
    idx = 0;
    while (idx < player->c_tot)
    {
        if (c_pos[idx] != -1 && c_pos[idx] == p_pos)
        {
            player->c_cur++;
            _collec_c2t(game, c_pos[idx]);
            _collec_display(player);
            c_pos[idx] = -1;
        }
        idx++;
    }
}

void    _collec_display(t_player *player)
{
    int c_left;

    c_left = player->c_tot - player->c_cur;
    if (c_left == 0)
        printf("player has collected all items!\n");
    else
        printf("player has collected item (%d items left)\n", c_left);
}

void    _collec_c2t(t_game *game, int c_pos)
{
    int x_pos;
    int y_pos;

    x_pos = c_pos / 100;
    y_pos = c_pos % 100;
    ft_put_img64(game, game->road.ptr, x_pos, y_pos);
}