#include "libft.h"

char    *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    unsigned int    s_len;   
    unsigned int    idx;
    char            *new_str;

    if (!s || !f == 0)
        return (0);
    s_len = ft_strlen(s);
    new_str = (char *)malloc((s_len + 1) * sizeof(char));
    if (!new_str)
        return (0);
    idx = 0;
    while (idx < s_len)
    {
        new_str[idx] = f(idx, s[idx]);
        idx++;
    }
    new_str[idx] = '\0';
    return (new_str);
}