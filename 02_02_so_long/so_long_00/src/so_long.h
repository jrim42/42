/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:24:13 by jrim              #+#    #+#             */
/*   Updated: 2022/05/01 16:50:27 by jrim             ###   ########.fr       */
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

# define RED "\\033[0;31m"
# define GRN "\\033[0;32m"
# define YLW "\\033[0;33m"
# define BLU "\\033[0;36m"
# define DFL "\\033[0;37m"

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
	int		rows;
	int		cols;
	int		*c_pos;
	char	**coord;
}			t_map;

typedef struct s_player
{
	t_img	p_img;
	int		step;
	int		c_tot;
	int		c_cur;
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
	t_map		maps;
	int			end;
}				t_game;

// so_long.c
int		main_loop(t_game *game);
int		game_end(t_game *game);

// _map_gen.c
void	map_gen(t_game *game);

// _map_read.c
void	map_read(t_game *game, char *map_src);
void	_map_cnt(t_game *game, char *map_src);
void	_map_malloc(t_game *game);

// _map_check.c
void	map_check(t_game *game, char **map);
void	_init_val(t_val *val);
void	_check_elm(t_game *game, char **map);

// _init.c
void	game_init(t_game *game);
void	img_init(t_game *game);
void	player_init(t_game *game, t_player *player);
void	collec_init(t_game *game, t_map *map);

// _key.c
int		key_press(int key, t_game *game);

// _move.c
void	_move(t_game *game, t_player *player, int dir);
int		_move_stuck(char **map, t_player *player, int dir);
void	_move_display(t_player *player, int dir);
void	_end_check(t_game *game, t_player *player);

// _collec.c
void	_collec(t_game *game, t_player *player);
void	_collec_display(t_player *player);
void	_collec_c2t(t_game *game, int c_pos);

// _utils.c
void	err_exit(char *msg);
void	_msg_display(char *msg1, int num, char *msg2);
void	*ft_xpm_to_img(t_game *game, char *str);
void	ft_put_img(t_game *game, void *img_ptr, int x, int y);

// _unnecessary.c
void	_move_display(t_player *player, int dir);

#endif
