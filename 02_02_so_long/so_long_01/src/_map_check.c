/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _map_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:55:29 by jrim              #+#    #+#             */
/*   Updated: 2022/05/01 17:36:01 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_check(t_game *game, char **map);
void	_init_val(t_val *val);
void	_check_elm(t_game *game, char **map);
void	_check_wall(t_game *game, char **map);

void	map_check(t_game *game, char **map)
{
	game->maps.val = (t_val *)malloc(sizeof(t_val));
	if (!game->maps.val)
		msg_err("[error] : allocation failed");
	_init_val(game->maps.val);
	_check_elm(game, map);
	_check_wall(game, map);
	free(game->maps.val);
}

void	_init_val(t_val *val)
{
	val->_c = 0;
	val->_e = 0;
	val->_p = 0;
}

void	_check_elm(t_game *game, char **map)
{
	int		x;
	int		y;
	t_val	*val;

	y = -1;
	val = game->maps.val;
	while (++y < game->maps.cols)
	{
		x = -1;
		while (++x < game->maps.rows)
		{
			if (ft_strchr(ELM, map[y][x]) == 0)
				msg_err("[error] : invalid char in map");
			else if (map[y][x] == 'P')
				val->_p = 1;
			else if (map[y][x] == 'C')
				val->_c++;
			else if (map[y][x] == 'E')
				val->_e = 1;
		}
	}
	if (val->_p * val->_c * val->_e == 0)
		msg_err("[error] : map element unfulfilled");
	game->player.c_tot = val->_c;
}

void	_check_wall(t_game *game, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->maps.cols)
	{
		x = 0;
		while (x < game->maps.rows)
		{
			if (y % (game->maps.cols - 1) != 0 \
				&& x % (game->maps.rows - 1) != 0)
				break ;
			if (map[y][x] != '1')
				msg_err("[error] : invalid map - no walls!");
			x++;
		}
		y++;
	}
}
