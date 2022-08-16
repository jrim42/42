/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_paint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 22:42:02 by jrim              #+#    #+#             */
/*   Updated: 2022/08/16 22:52:49 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "micro_paint.h"

// micro_paint
void	micro_paint(char **map, t_info *info, t_rect *rect);
int		is_in_rect(t_rect *rect, float x, float y);

// utils 
int		ft_strlen(char *str);
void	ft_putstr(char *str);
int		print_error(char *msg);
void	print_map(char **map, t_info info);

//------------------------ micro_paint -----------------------//

int	main(int argc, char **argv)
{
	t_info		info;
	t_rect		rect;
	FILE		*file;
	char		**map;
	int			i;
	int			j;
	int			ret;
	
	// basic error check + get info
	if (argc != 2)
		return(print_error("Error: argument"));
	file = fopen(argv[1], "r");
	if (file == NULL)
		return(print_error("Error: Operation file corrupted"));
	if (fscanf(file, "%d %d %c\n", &info.w, &info.h, &info.background) != 3)
		return(print_error("Error: Operation file corrupted"));
	if (!(info.w > 0 && info.w <= 300 && info.h > 0 && info.h <= 300))
		return(print_error("Error: Operation file corrupted"));
	
	// map allocation
	map = (char **)malloc(sizeof(char *) * (info.h + 1));
	if (map == NULL)
		return (1);
	i = -1;
	while (++i < info.h)
	{
		map[i] = (char *)malloc(sizeof(char) * (info.w + 1));
		if (map[i] == NULL)
			return (1);
		j = -1;
		while (++j < info.w)
			map[i][j] = info.background;
		map[i][j] = '\0';
	}
	map[i] = 0;

	//
	while ((ret = fscanf(file, "%c %f %f %f %f %c\n", &rect.type, &rect.x, &rect.y, &rect.w, &rect.h, &rect.color)) == 6)
	{
		if (rect.w <= (float)0 || rect.h <= (float)0 || !(rect.type == 'r' || rect.type == 'R'))
			return (print_error("Error: Operation file corrupted"));
		micro_paint(map, &info, &rect);
	}
	if (ret != -1)
		return (print_error("Error: Operation file corrupted"));

	print_map(map, info);
	
	// map free
	i = -1;
	while (++i < info.h)
		free(map[i]);
	free(map);
	fclose(file);

	return (0);
}

void	micro_paint(char **map, t_info *info, t_rect *rect)
{
	int	i;
	int	j;
	int	ret;

	i = -1;
	while (++i < info->h)
	{
		j = -1;
		while (++j < info->w)
		{
			ret = is_in_rect(rect, j, i);
			if ((rect->type == 'r' && ret == 2) || (rect->type == 'R' && ret != 0))
				map[i][j] = rect->color;
		}
	}
}

int	is_in_rect(t_rect *rect, float x, float y)
{
	if (((x < rect->x || (rect->x + rect->w< x)) || (y < rect->y)) || (rect->y + rect->h < y))
		return (0);
	if (((x - rect->x < (float)1) || ((rect->x + rect->w) - x < (float)1)) ||
		((y - rect->y < (float)1 || ((rect->y + rect->h) - y < (float)1))))
		return (2);
	return (1);
}

//-------------------------- utils --------------------------//

int	ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

int	print_error(char *msg)
{
	write(1, msg, ft_strlen(msg));
	write(1, "\n", 1);
	return (1);
}

void	print_map(char **map, t_info info)
{
	int i;
	int j;

	i = -1;
	while (++i < info.h)
	{
		j = -1;
		while (++j < info.w)
			write(1, &map[i][j], 1);
		write(1, "\n", 1);
	}
}