#include "libft.h"

char    *ft_strrchr(const char *s, int c)
{
    unsigned int    idx;
    unsigned int    s_len;
    char            *ptr;

    idx = 0;
    s_len = ft_strlen(s) + 1;
    ptr = 0;
    while (idx < s_len)
    {
        if (s[idx] == (char)c)
            ptr = (char *)s + idx;
        idx++;
    }
    return (ptr);    
}

int main(void)
{
    printf("%s\n", ft_strrchr("abcabc", 97));
    printf("%p\n", ft_strrchr("abcabc", 97));
    printf("%s\n", ft_strrchr("abcabc", 0));
    printf("%p\n", ft_strrchr("abcabc", 0));
    printf("%s\n", ft_strrchr("abcabc", 100));
    printf("%p\n", ft_strrchr("abcabc", 100));
}