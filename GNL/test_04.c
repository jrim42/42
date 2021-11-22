#include "get_next_line.h"

char    *gnl(int fd);
char    *cut_eol_front(const char *buf);
char    *cut_eol_back(const char *buf);

int	main(void)
{
    int     fd;
    char    *tmp;

    fd = open("test", O_RDONLY);
    printf ("fd : %d\n", fd);
    while ((tmp = gnl(fd)) != 0)
        printf("^%s", tmp);
    close(fd);
    return (0);
}

char    *gnl(int fd)
{
    int         byte;
    char        buf[BUFFER_SIZE + 1];
    static char *depot[10];
    int         idx;

    printf("GNL CALLED\n");
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (0);
    byte = read(fd, buf, BUFFER_SIZE);
    buf[byte] = '\0';
    printf ("buf : %s\n", buf);
    idx = 0;
    while (ft_strchr(buf, '\n') == 0 && byte > 0)
    {
        printf("while in\n");
        depot[idx] = ft_strjoin(depot[idx], buf);
        printf ("depot[%d] : %s\n", idx, depot[idx]);
        byte = read(fd, buf, BUFFER_SIZE);
    }
    if (ft_strchr(buf, '\n') != 0)
    {
        printf("if in\n");
        depot[idx] = ft_strjoin(depot[idx], cut_eol_front(buf));
        depot[idx + 1] = ft_strjoin(depot[idx + 1], cut_eol_back(buf));
    }
    return (depot[idx++]);
}

char    *cut_eol_front(const char *buf)
{
    char    *ptr;
    char    *eol_pos;

    ptr = (char *)buf;
    eol_pos = ft_strchr(buf, '\n') + 1;
    *(ptr + (int)(eol_pos - ptr)) = '\0';
    return (ft_strdup(ptr));
}

char    *cut_eol_back(const char *buf)
{
    char    *eol_pos;

    eol_pos = ft_strchr(buf, '\n') + 1;
    return (ft_strdup(eol_pos));
}
