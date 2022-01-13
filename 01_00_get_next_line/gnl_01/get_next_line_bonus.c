/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:15:32 by jrim              #+#    #+#             */
/*   Updated: 2021/11/23 20:06:01 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*fill_depot(int fd, char *depot_fd);
char	*trim_eol(char *depot_fd);
char	*trim_depot(char *depot_fd);

char	*get_next_line(int fd)
{
	static char	*depot[OPEN_MAX];
	char		*one_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX - 1)
		return (0);
	depot[fd] = fill_depot(fd, depot[fd]);
	if (!depot[fd] || !(*(depot[fd])))
	{
		if (depot[fd])
			free(depot[fd]);
		return (0);
	}
	one_line = trim_eol(depot[fd]);
	depot[fd] = trim_depot(depot[fd]);
	return (one_line);
}

char	*fill_depot(int fd, char *depot_fd)
{
	char	*buf;
	int		byte;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (0);
	byte = 1;
	while (byte > 0 && ft_strchr(depot_fd, '\n') == 0)
	{
		byte = read(fd, buf, BUFFER_SIZE);
		if (byte == -1)
		{
			free(buf);
			return (0);
		}
		buf[byte] = '\0';
		depot_fd = ft_strjoin(depot_fd, buf);
	}
	free(buf);
	return (depot_fd);
}

char	*trim_eol(char *depot_fd)
{
	int	eol_idx;

	if (ft_strchr(depot_fd, '\n') == 0)
		return (depot_fd);
	eol_idx = (int)(ft_strchr(depot_fd, '\n') - depot_fd);
	return (ft_strndup(depot_fd, eol_idx + 1));
}

char	*trim_depot(char *depot_fd)
{
	int		eol_idx;
	int		trimmed_len;
	char	*new_depot;

	if (ft_strchr(depot_fd, '\n') == 0)
		return (0);
	eol_idx = (int)(ft_strchr(depot_fd, '\n') - depot_fd);
	if (depot_fd[eol_idx + 1] == '\0')
	{
		free(depot_fd);
		return (0);
	}
	trimmed_len = ft_strlen(depot_fd) - (eol_idx + 1);
	new_depot = ft_strndup(depot_fd + eol_idx + 1, trimmed_len);
	free(depot_fd);
	return (new_depot);
}
