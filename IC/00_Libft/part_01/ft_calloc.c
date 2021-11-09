#include "libft.h"

void    *ft_calloc(size_t count, size_t size)
{
    char    *tmp;
    int     idx;

    tmp = (char *)malloc(count * size);
    if (!tmp)
        return (0);
    idx = 0;
    // ft_memset(tmp, 0, count * size); ?
    while (idx < count)
        tmp[idx++] = 0; 
    return (tmp);
}