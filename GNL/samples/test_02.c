#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char    *cut_eol(const char *str);

int	main(void)
{
    // static char *depot;
	char	    buf[BUFFER_SIZE + 1];
    int		    byte;
    int         fd;

	fd = open("test", O_RDONLY);
	if (fd < 0 || BUFFER_SIZE <= 0)
        return (-1);
    byte = read(fd, buf, BUFFER_SIZE);
    buf[byte] = '\0';
    printf("%s", buf);
    // if (ft_strchr(buf, '\n') == 0)
    //     depot = ft_strjoin(depot, buf);
    byte = read(fd, buf, BUFFER_SIZE);
    buf[byte] = '\0';
    printf("%s", buf);
    byte = read(fd, buf, BUFFER_SIZE);
    buf[byte] = '\0';
    printf("%s", buf);
    byte = read(fd, buf, BUFFER_SIZE);
    buf[byte] = '\0';
    printf("%s", buf);
    byte = read(fd, buf, BUFFER_SIZE);
    buf[byte] = '\0';
    printf("%s", buf);
    // while ((byte = read(fd, buf, BUFFER_SIZE)) > 0)
    // {
    //     printf("%s", buf);
    //     buf[byte] = '\0';
    //     printf("%s", buf);
    //     depot = ft_strjoin(depot, buf);
    //     //if ()
    // }
    // while (ft_strchr(buf, '\n') == 0)
    // {
    //     buf[BUFFER_SIZE] = '\0';   
    //     depot[fd] = ft_strjoin(depot[fd], buf);
    //     byte = read(fd, buf, BUFFER_SIZE);
    // }
    // if (ft_strchr(buf, '\n') != 0)
    //     depot[fd] = cut_eol(buf);
    //depot[fd] = ft_strjoin(depot[fd], cut_eol(buf));
    // if (byte < BUFFER_SIZE)
    return (0);
}

char    *cut_eol(const char *buf)
{
    char    *ptr;
    char    *eol_pos;

    ptr = (char *)buf;
    eol_pos = ft_strchr(buf, '\n') + 1;
    *(ptr + (int)(eol_pos - ptr)) = '\0';
    return (ft_strdup(ptr));
}