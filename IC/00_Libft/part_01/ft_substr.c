#include "libft.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    unsigned int    s_len;
    unsigned int    sub_idx;
    char            *substr;

    s_len = ft_strlen(s);
    if (start > s_len )
        return (0);
    sub_idx = 0;
    if (s_len - start >= len)
    {
        substr = (char *)malloc((len + 1) * sizeof(char));
        if (!(substr))
            return (0);
        while (len-- > 0)
            substr[sub_idx++] = s[start++];
        substr[sub_idx] = '\0';
    }
    else
    {
        substr = (char *)malloc((s_len - start + 1) * sizeof(char));
        if (!(substr))
            return (0);
        while (s[start] != '\0')
            substr[sub_idx++] = s[start++];
        substr[sub_idx] = '\0';     
    }
    return (substr);
}