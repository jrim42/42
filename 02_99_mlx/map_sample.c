/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_sample.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 21:28:27 by jrim              #+#    #+#             */
/*   Updated: 2022/03/12 18:26:58 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "help.h"

#define TILES 60
#define COL 15
#define ROW 15
#define WIDTH TILES * COL
#define HEIGHT TILES * ROW
#define X_EVENT_KEYPRESS 2
#define X_EVENT_EXIT 17
#define KEYCODE_EXIT 53
#define IMG_PATH "./img/"

typedef struct s_img
{
	void	*img_ptr;
	int		*data;
	int		h;
	int		w;
	int		bpp;
	int		size_line;
	int		endian;
} 			t_img;

typedef struct s_game
{
	void	*mlx_ptr;
	void 	*win_ptr;
	t_img 	img;
	t_img	player;
	t_img	tile;
	int 	map[ROW][COL];
} 			t_game;

void	minilibx_init(t_game *game);
void	img_init(t_game *game);
void	draw_pixels_of_tile(t_game *game, int row, int col);
void	draw_pixels_of_player(t_game *game, int row, int col);
void	*ft_xpm_to_img(t_game *game, char *str);
void	ft_put_img64(t_game *game, void *img_ptr, int x, int y);
void	draw_tiles(t_game *game);
void	map_init(t_game *game);
int		press_key(int keycode, t_game game);

int main(void)
{
	t_game game;

	minilibx_init(&game);
	img_init(&game);
	map_init(&game);
	mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, game.img.img_ptr, 0, 0);
	mlx_hook(game.win_ptr, X_EVENT_KEYPRESS, 0, &press_key, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}

void minilibx_init(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, WIDTH, HEIGHT, "map sample");
}

void img_init(t_game *game)
{
	game->img.img_ptr = mlx_new_image(game->mlx_ptr, WIDTH, HEIGHT);
	game->img.data = (int *)mlx_get_data_addr(game->img.img_ptr, &game->img.bpp, &game->img.size_line, &game->img.endian);
}

void draw_pixels_of_tile(t_game *game, int row, int col)
{
	row *= TILES;
	col *= TILES;
	game->tile.h = TILES;
	game->tile.w = TILES;
	game->tile.img_ptr = ft_xpm_to_img(game, "img/tile00.xpm");
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player.img_ptr, row, col);
}

void draw_pixels_of_player(t_game *game, int row, int col)
{
	row *= TILES;
	col *= TILES;
	game->tile.h = TILES;
	game->tile.w = TILES;
	game->tile.img_ptr = ft_xpm_to_img(game, "img/img60.xpm");
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->tile.img_ptr, row, col);
}

void	*ft_xpm_to_img(t_game *game, char *str)
{
	void	*img;

	img = mlx_xpm_file_to_image(game->mlx_ptr, str,
			&(game->img.w), &(game->img.h));
	return (img);
}

void draw_tiles(t_game *game)
{
	int row, col;

	row = 0;
	while (row < ROW)
	{
		col = 0;
		while (col < COL)
		{
			if (game->map[row][col] == 1)
				ft_put_img64(game, game->tile.img_ptr, col, row);
			else if (game->map[row][col] == 2)
				ft_put_img64(game, game->player.img_ptr, col, row);
			col++;
		}
		row++;
	}
}

void map_init(t_game *game)
{
	int src[ROW][COL] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1},
	{1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1},
	{1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1},
	{1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1},
	{1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1},
	{1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1},
	{1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
	{1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 2, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
	memcpy(game->map, src, sizeof(int) * ROW * COL);
	draw_tiles(game);
}

int	press_key(int keycode, t_game game)
{
	if (keycode == KEYCODE_EXIT)
		exit(0);
	return (0);
}
