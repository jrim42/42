#include "libft.h"

void    *ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
    unsigned int    idx;
    char            *dst_ptr;
    char            *src_ptr;

    idx = 0;
    dst_ptr = (char *)dst;
    src_ptr = (char *)src;
    while (idx < n)
    {
        dst_ptr[idx] = src_ptr[idx];
        idx++;
    }
    return (dst);
}