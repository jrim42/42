#include "libft.h"

char    *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    int     		idx;
	unsigned int	needle_len;
    char    		*ptr;

    idx = 0;
	needle_len = ft_strlen(needle);
    ptr = haystack;
    if (!haystack && !needle)
		return (haystack);
	while (idx <= len - needle_len)
	{
		if (ft_strncmp(ptr, needle, needle_len) == 0)
			return (ptr);
		idx++;
		ptr++;
	}
	return (0);
}