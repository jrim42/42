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

char    *get_next_line(int fd);
char    *eol_trim(char *depot);
char    *depot_trim(char *depot);

int	main(void)
{
    int     fd;
    char    *tmp;
    int     idx;

    fd = open("test", O_RDONLY);
    idx = 1;
    while ((tmp = get_next_line(fd)) != 0)
    {
        printf("----- %d -----\n", idx);
        printf("%s", tmp);
        printf("-------------\n");
        idx++;
        free(tmp);
    }
    close(fd);
    return (0);
}

char    *get_next_line(int fd)
{
    static char *depot;
    char	    *buf;
    char        *line;
    int		    byte;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (0);
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
    if (!(depot))
        return (0);
    line = eol_trim(depot);
    depot = depot_trim(depot);
    return (line);
}

char    *eol_trim(char *depot)
{
    int eol_idx;

    if (depot[0] == '\0')
        return (0);
    if (ft_strchr(depot, '\n') == 0)
        return (depot);
    eol_idx = (int)(ft_strchr(depot, '\n') - depot);
    return (ft_strndup(depot, eol_idx + 1));
}

char    *depot_trim(char *depot)
{
    int     eol_idx;
    int     trimmed_len;
    char    *new_depot;


    if (ft_strchr(depot, '\n') == 0)
        return (0);
    eol_idx = (int)(ft_strchr(depot, '\n') - depot);
    trimmed_len = ft_strlen(depot) - (eol_idx + 1);
    new_depot = ft_strndup(depot + eol_idx + 1, trimmed_len);
    free(depot);
    return (new_depot);
}
