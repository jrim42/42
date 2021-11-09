#include "libft.h"

void    *ft_memchr(const void *s, int c, size_t n)
{
    unsigned int    idx;
    unsigned char   *ptr;

    idx = 0;
    ptr = (unsigned char *)s;
    while (idx < n)
    {
        if (ptr[idx] == (unsigned char)c)
            return (&s[idx]); // (s + idx)도 가능?
        idx++;
    }
    return (0);
}