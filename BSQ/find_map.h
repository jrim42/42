/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 22:59:50 by jrim              #+#    #+#             */
/*   Updated: 2021/09/29 19:22:07 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIND_MAP_H
# define FIND_MAP_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_map_info
{
	int		lines;
	int		line_size;
	int		first_line;
	char	ch[3];
}			t_map_info;

int				is_map_valid(char *file, t_map_info *g_info);
int				get_first_line(char *file, t_map_info *g_info);
int				get_line_size(char *ch_map, t_map_info *g_info);
int				get_lines(char *str, t_map_info *g_info);
int				get_chars(char *str, t_map_info *g_info);
int				get_copy(char *ch_map, unsigned int **num_map, \
							t_map_info g_info);
int				put_nbr(unsigned int *map, t_map_info g_info);
int				check_line_size(char *ch_map, t_map_info *g_info);
void			find_square(char *ch_map, \
							unsigned int *num_map, t_map_info g_info);
int				search_min(int row, int col, \
							unsigned int *num_map, t_map_info g_info);
unsigned int	search_max(int *max_idx, \
							unsigned int *num_map, t_map_info g_info);
void			display_result(int max_idx, int max_val, \
								char *ch_map, t_map_info g_info);
char			*get_ch_map(void);
void			solve_map(char *ch_map);

int				get_input(char *buff, int byte);
int				file_to_ch_map(char **c_map, char *file);

#endif
