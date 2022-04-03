/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _key.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:06:36 by jrim              #+#    #+#             */
/*   Updated: 2022/04/03 14:46:23 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int     key_press(int key, t_game *game);

int     key_press(int key, t_game *game)
{
    if (key == KEY_EXIT)
		exit(0);
    else if (key == KEY_A || key == KEY_LF)
        _move(game, &game->player, DIR_LF);
    else if (key == KEY_S || key == KEY_DW)
        _move(game, &game->player, DIR_DW);
    else if (key == KEY_D || key == KEY_RT)
        _move(game, &game->player, DIR_RT);
    else if (key == KEY_W || key == KEY_UP)
        _move(game, &game->player, DIR_UP);
	return (0);
}
