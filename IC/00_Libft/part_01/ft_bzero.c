#include "libft.h"

void    ft_bzero(void *s, size_t n)
{
    char    *ptr;
    size_t  idx;

    ptr = s;
    idx = 0;
    while (idx < n)
        ptr[idx++] = 0;
}