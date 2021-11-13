#include "libft.h"

char    *ft_strchr(const char *s, int c)
{
    unsigned int    idx;
    unsigned int    s_len;
    char            *ptr;

    idx = 0;
    s_len = ft_strlen(s) + 1;
    ptr = (char *)s;
    while (idx < s_len)
    {
        if (*ptr == (char)c)
            return (ptr);
        idx++;
        ptr++; 
    }
    return (0);
}

int main(void)
{
    printf("%s\n", ft_strchr("abc", 97));
    printf("%p\n", ft_strchr("abc", 97));
    printf("%s\n", ft_strchr("abc", 0));
    printf("%p\n", ft_strchr("abc", 0));
    printf("%s\n", ft_strchr("abc", 100));
    printf("%p\n", ft_strchr("abc", 100));
}