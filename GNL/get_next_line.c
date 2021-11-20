/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:15:32 by jrim              #+#    #+#             */
/*   Updated: 2021/11/21 00:05:09 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    static char	buffer[BUFFER_SIZE + 1];
    char        *storage[OPEN_MAX];
    int		    byte;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    byte = read(fd, buffer, BUFFER_SIZE);
    while (byte > 0)
    {
        buffer[byte] = '\0';
        storage[fd] = ft_strjoin(storage[fd], buffer);
    }
    //return ();
}