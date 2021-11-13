#include "libft.h"

void    ft_bzero(void *s, size_t n)
{
    char            *ptr;
    unsigned int    idx;

    ptr = (char *)s;
    idx = 0;
    while (idx < n)
        ptr[idx++] = 0;
}