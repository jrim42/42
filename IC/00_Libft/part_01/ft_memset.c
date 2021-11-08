#include "libft.h"

void    *ft_memset(void *b, int c, size_t len)
{
    char    *ptr;
    size_t  idx;

    ptr = b;
    idx = 0;
    while (idx < len)
        ptr[idx++] = c;
    return (b);
}