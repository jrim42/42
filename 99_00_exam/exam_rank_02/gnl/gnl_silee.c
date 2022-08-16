/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_silee.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 13:23:57 by jrim              #+#    #+#             */
/*   Updated: 2022/08/16 13:35:10 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

char	*get_next_line(int fd)
{
    int     byte;
    char    buf[2];
    int     i;
    char    save[10000000];
    char    *line;

    if (fd < 0)
        return (NULL);
    byte = read(fd, &buf, 1);
    buf[byte] = '\0';
    if (buf[0] == '\n' && byte == 0)
    {
        line = ft_strdup(buf);
        return (line);
    }
    i = 0;
    while (byte > 0)
    {
        save[i++] = buf[0];
        if (buf[0] == '\n')
            break ;
        byte = read(fd, &buf, 1);
        buf[byte] = '\0';
    }
    if (byte <= 0 && i == 0)
        return (NULL);
    save[i] = '\0';
    line = ft_strdup(save);
    return (line);
}

//----------------------------------------//

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *str)
{
	char	*new_str;
	int		i;
	int		len;

	len = ft_strlen(str);
	new_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	i = -1;
	while (++i < len)
		new_str[i] = str[i];
	new_str[i] = '\0';
	return (new_str);
}