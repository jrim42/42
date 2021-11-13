#include "libft.h"

void    *ft_calloc(size_t count, size_t size)
{
    char            *ptr;
    unsigned int    idx;

    ptr = (char *)malloc(count * size);
    if (!ptr)
        return (0);
    idx = 0;
    while (idx < count)
        ptr[idx++] = 0; 
    return (ptr);
}

/*
void    *ft_calloc(size_t count, size_t size)
{
    char    *ptr;

    ptr = (char *)malloc(count * size);
    if (!ptr)
        return (0);
    ft_memset(ptr, 0, count * size);
    return (ptr);
}
*/