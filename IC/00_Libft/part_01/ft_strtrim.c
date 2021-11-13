#include "libft.h"

int	is_set(char ch, char const *set)
{
	int	idx;

	idx = 0;
	while (set[idx] != '\0')
	{
		if (ch == set[idx])
			return (1);
		idx++;
	}
	return (0);
}

char    *ft_strtrim(char const *s1, char const *set)
{
    char    *ptr;
    int     idx;
    int     s_len;
    char    *new_str;

    ptr = s1;
    idx = 0;
    s_len = ft_strlen(s1);
    while (ptr[idx] != '\0')
    {
        if (isset(ptr[idx], set) == 1)
        {
            ptr[idx] = '\0';
            s_len--;
        }    
        idx++;
    }
    new_str = (char *)malloc((s_len + 1) * sizeof(char));
    if (!(new_str))
        return (0);
    idx = 0;
    s_len = ft_strlen(s1);
    while (idx < s_len)
    {
        if (*ptr != '\0')
            new_str[idx] = *ptr;
        idx++;
        ptr++;
    }
    new_str[idx] = '\0';
    return (new_str);
}