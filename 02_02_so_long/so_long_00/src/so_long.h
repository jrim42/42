/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:24:13 by jrim              #+#    #+#             */
/*   Updated: 2022/04/03 14:25:58 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

# define TILES 60
# define ELM "01PEC"
# define X_EVENT_KEYPRESS 2
# define X_EVENT_EXIT 17

# define KEY_EXIT 53
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_UP 126
# define KEY_DW 125
# define KEY_LF 123
# define KEY_RT 124

# define DIR_UP 0
# define DIR_DW 1
# define DIR_LF 2 
# define DIR_RT 3

typedef struct s_img
{
	void	*ptr;
	int		*data;
	int		h;
	int		w;
}			t_img;

typedef struct s_val
{
	int		_p;
	int		_e;
	int		_c;
}			t_val;

typedef struct s_map
{
	t_val	*val;
	int 	rows;
	int 	cols;
	char	**coord;
}			t_map;

typedef struct s_player
{
	t_img	p_img;
	int		step;
	int		collec;
	int		x_pos;
	int		y_pos;
	int		x_end;
	int		y_end;
	int		dir;
}			t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			fps;
	t_img		img64;
	t_img		road;
	t_img		wall;
	t_img		exit;
	t_img		collec;
	t_player	player;
	t_map 		maps;
	int			end;
}				t_game;

// so_long.c
void	err_exit(char *msg);
int		main_loop(t_game *game);
int		game_end(t_game *game);

// _init.c
void	game_init(t_game *game);
void    img_init(t_game *game);
void	player_init(t_game *game, t_player *player);

// _key.c
int     key_press(int key, t_game *game);
void    _up(t_game *game, t_player *player);
void    _down(t_game *game, t_player *player);
void    _left(t_game *game, t_player *player);
void    _right(t_game *game, t_player *player);

// _map_gen.c
void	map_gen(t_game *game);

// _map_read.c
void	map_read(t_game *game, char *map_src);
void	_map_cnt(t_game *game, char *map_src);
void	_map_malloc(t_game *game);

// _map_check.c
void    map_check(t_game *game, char **map);
void    _init_val(t_val *val);
void    _check_elm(t_game *game, char **map);

// _img_utils.c
void	*ft_xpm_to_img(t_game *game, char *str);
void	ft_put_img64(t_game *game, void *img_ptr, int x, int y);

#endif