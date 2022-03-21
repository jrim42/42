/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:24:13 by jrim              #+#    #+#             */
/*   Updated: 2022/03/21 18:30:36 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

#define TILES 60
#define COL 15
#define ROW 15
#define WIDTH TILES * COL
#define HEIGHT TILES * ROW
#define X_EVENT_KEYPRESS 2
#define X_EVENT_EXIT 17
#define KEYCODE_EXIT 53

typedef struct s_img
{
	void	*ptr;
	int		*data;
	int		h;
	int		w;
}			t_img;

typedef struct s_map
{
	int 	rows;
	int 	cols;
	int		coord[ROW][COL];
}			t_map;

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
	t_img		player;
	t_map 		maps;
}				t_game;

int		main_loop(t_game *game);
void	init_map(t_game *game);
int		press_key(int keycode);

void    map_elm_init(t_game *game);
void	map_gen(t_game *game);
void	*ft_xpm_to_img(t_game *game, char *str);
void	ft_put_img64(t_game *game, void *img_ptr, int x, int y);

void 	init_map(t_game *game);

#endif