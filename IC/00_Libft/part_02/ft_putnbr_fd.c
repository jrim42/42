#include "libft.h"

void    ft_putnbr_fd(int n, int fd)
{
    char    *s;

    if (fd < 0)
        return ;
    s = ft_atoi(n);
    write(fd, s, ft_strlen(s) - 1);    
}