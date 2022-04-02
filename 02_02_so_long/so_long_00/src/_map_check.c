/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _map_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:55:29 by jrim              #+#    #+#             */
/*   Updated: 2022/04/02 18:38:46 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    map_check(t_game *game, char **map);
void    _init_val(t_val *val);
void    _check_elm(t_game *game, char **map);
void    _check_wall(t_game *game, char **map);

void    map_check(t_game *game, char **map)
{
    game->maps.val = (t_val *)malloc(sizeof(t_val));
    if (!game->maps.val)
        err_exit("[error] : allocation failed");
    _init_val(game->maps.val);
    _check_elm(game, map);
    _check_wall(game, map);
    free(game->maps.val);
}

void    _init_val(t_val *val)
{
    val->_c = 0;
    val->_e = 0;
    val->_p = 0;
}

void     _check_elm(t_game *game, char **map)
{
    int     col;
    int     row;
    char    ch;
    t_val   *val;
    
    col = 0;
    val = game->maps.val;
    while (col < game->maps.cols)
    {
        row = 0;
        while (row < game->maps.rows)
        {
            ch = map[col][row];
            if (ft_strchr(ELM, ch) == 0)
                err_exit("[error] : invalid char in map");
            else if (ch == 'P')
                val->_p = 1;
            else if (ch == 'C')
                val->_c = 1;
            else if (ch == 'E')
                val->_e = 1;
            row++;
        }
        col++;
    }
    if (val->_p * val->_c * val->_e == 0)
        err_exit("[error] : map element unfulfilled");
}

void    _check_wall(t_game *game, char **map)
{
    int     col;
    int     row;
    
    col = 0;
    while (col < game->maps.cols)
    {
        row = 0;
        while (row < game->maps.rows)
        {
            if (col % (game->maps.cols - 1) != 0 && row % (game->maps.rows - 1) != 0)
                break ;
            if (map[col][row] != '1')
                err_exit("[error] : invalid map - no walls!");
            row++;
        }
        col++;
    }
}