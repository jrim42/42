#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    unsigned int    idx;
    unsigned char   *s1_ptr;
    unsigned char   *s2_ptr;

    idx = 0;
    s1_ptr = (unsigned char *)s1;
    s2_ptr = (unsigned char *)s2;
    if (n == 0)
        return (0);
    while (idx < n)
    {
        if (s1_ptr[idx] != s2_ptr[idx])
            return (s1_ptr[idx] - s2_ptr[idx]);
        idx++;
    }
    return (0);
}