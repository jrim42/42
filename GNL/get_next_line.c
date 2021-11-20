/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:15:32 by jrim              #+#    #+#             */
/*   Updated: 2021/11/20 18:35:11 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    char	buffer[BUFFER_SIZE + 1];
    char    *storage[MAX];
    int		size;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    size = read(fd, buffer, BUFFER_SIZE);
    while (size > 0)
    {
        buffer[size] = '\0';
        storage[fd] = ft_strjoin(storage[fd], buffer);
    }
    //return ();
}