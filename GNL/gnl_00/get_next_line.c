/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:15:32 by jrim              #+#    #+#             */
/*   Updated: 2021/11/23 20:06:01 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_depot(int fd, char *depot);
char	*trim_eol(char *depot);
char	*trim_depot(char *depot);

char	*get_next_line(int fd)
{
	static char	*depot;
	char		*one_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	depot = fill_depot(fd, depot);
	if (!depot)
		return (0);
	if (!(*depot))
	{
		free(depot);
		return (0);
	}
	one_line = trim_eol(depot);
	depot = trim_depot(depot);
	return (one_line);
}

char	*fill_depot(int fd, char *depot)
{
	char	*buf;
	int		byte;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (0);
	byte = 1;
	while (byte > 0 && ft_strchr(depot, '\n') == 0)
	{
		byte = read(fd, buf, BUFFER_SIZE);
		if (byte == -1)
		{
			free(buf);
			return (0);
		}
		buf[byte] = '\0';
		depot = ft_strjoin(depot, buf);
	}
	free(buf);
	return (depot);
}

char	*trim_eol(char *depot)
{
	int	eol_idx;

	if (depot[0] == '\0')
		return (0);
	if (ft_strchr(depot, '\n') == 0)
		return (depot);
	eol_idx = (int)(ft_strchr(depot, '\n') - depot);
	return (ft_strndup(depot, eol_idx + 1));
}

char	*trim_depot(char *depot)
{
	int		eol_idx;
	int		trimmed_len;
	char	*new_depot;

	if (ft_strchr(depot, '\n') == 0)
		return (0);
	eol_idx = (int)(ft_strchr(depot, '\n') - depot);
	if (depot[eol_idx + 1] == '\0')
	{
		free(depot);
		return (0);
	}
	trimmed_len = ft_strlen(depot) - (eol_idx + 1);
	new_depot = ft_strndup(depot + eol_idx + 1, trimmed_len);
	free(depot);
	return (new_depot);
}
