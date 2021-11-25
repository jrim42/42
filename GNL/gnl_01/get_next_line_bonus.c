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

char	*fill_depot(int fd, char **depot);
char	*trim_eol(int fd, char **depot);
char	*trim_depot(int fd, char **depot);

char	*get_next_line(int fd)
{
	static char	*depot[OPEN_MAX];
	char		*one_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	depot[fd] = fill_depot(fd, &depot[fd]);
	if (!depot[fd] || !(*(depot[fd])))
	{
		free(depot[fd]);
		return (0);
	}
	one_line = trim_eol(fd, &depot[fd]);
	depot[fd] = trim_depot(fd, &depot[fd]);
	return (one_line);
}

char	*fill_depot(int fd, char **depot)
{
	char	*buf;
	int		byte;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (0);
	byte = 1;
	while (byte > 0 && ft_strchr(depot[fd], '\n') == 0)
	{
		byte = read(fd, buf, BUFFER_SIZE);
		if (byte == -1)
		{
			free(buf);
			return (0);
		}
		buf[byte] = '\0';
		depot[fd] = ft_strjoin(depot[fd], buf);
	}
	free(buf);
	return (depot[fd]);
}

char	*trim_eol(int fd, char **depot)
{
	int	eol_idx;

	if (ft_strchr(depot[fd], '\n') == 0)
		return (depot[fd]);
	eol_idx = (int)(ft_strchr(depot[fd], '\n') - depot[fd]);
	return (ft_strndup(depot[fd], eol_idx + 1));
}

char	*trim_depot(int fd, char **depot)
{
	int		eol_idx;
	int		trimmed_len;
	char	*new_depot;

	if (ft_strchr(depot[fd], '\n') == 0)
		return (0);
	eol_idx = (int)(ft_strchr(depot[fd], '\n') - depot[fd]);
	if (*(depot[fd] + eol_idx + 1) == '\0')
	{
		free(depot[fd]);
		return (0);
	}
	trimmed_len = ft_strlen(depot[fd]) - (eol_idx + 1);
	new_depot = ft_strndup(depot[fd] + eol_idx + 1, trimmed_len);
	free(depot[fd]);
	return (new_depot);
}
