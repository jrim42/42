/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_paint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 21:45:20 by jrim              #+#    #+#             */
/*   Updated: 2022/08/16 22:30:38 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "mini_paint.h"

// mini_paint
void	mini_paint(char **map, t_info *info, t_circle *cir);
int		is_in_circle(t_circle *cir, float x, float y);

// utils 
int		ft_strlen(char *str);
void	ft_putstr(char *str);
int		print_error(char *msg);
void	print_map(char **map, t_info info);

//------------------------ mini_paint -----------------------//

int	main(int argc, char **argv)
{
	t_info		info;
	t_circle	cir;
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
	while ((ret = fscanf(file, "%c %f %f %f %c\n", &cir.type, &cir.x, &cir.y, &cir.r, &cir.color)) == 5)
	{
		if (cir.r <= (float)0 || !(cir.type == 'c' || cir.type == 'C'))
			return (print_error("Error: Operation file corrupted"));
		mini_paint(map, &info, &cir);
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

void	mini_paint(char **map, t_info *info, t_circle *cir)
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
			ret = is_in_circle(cir, j, i);
			if ((cir->type == 'c' && ret == 2) || (cir->type == 'C' && ret != 0))
				map[i][j] = cir->color;
		}
	}
}

int	is_in_circle(t_circle *cir, float x, float y)
{
	float	distance;

	distance = sqrtf(powf(x - cir->x, 2) + powf(y - cir->y, 2));
	if (distance > cir->r)	// out of circle
		return (0);
	if ((cir->r - distance) < (float)1)	
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