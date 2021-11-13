#include "libft.h"

void    *ft_memset(void *b, int c, size_t len)
{
    char            *ptr;
    unsigned int    idx;

    ptr = (char *)b;
    idx = 0;
    while (idx < len)
        ptr[idx++] = (unsigned char)c;
    return (b);
}