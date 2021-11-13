#include "libft.h"
#include <string.h>

char    *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    unsigned int    idx;
	unsigned int	needle_len;
    char    		*ptr;

    idx = 0;
	needle_len = ft_strlen(needle);
    ptr = (char *)haystack;
    if (!haystack && !needle)
		return (ptr);
	while (idx + needle_len <= len)
	{
		if (ft_strncmp(ptr, needle, needle_len) == 0)
			return (ptr);
		idx++;
		ptr++;
	}
	return (0);
}

int	main(void)
{
	printf("%s\n", ft_strnstr("haystack", "hay", 5));
	printf("%s\n", strnstr("haystack", "hay", 5));
	printf("%p\n", ft_strnstr("haystack", "hay", 2));
	printf("%p\n", strnstr("haystack", "hay", 2));
	printf("%p\n", ft_strnstr("", "a", 1));
	printf("%p\n", strnstr("", "a", 1));
	printf("%p\n", ft_strnstr("abc", "", 3));
	printf("%p\n", strnstr("abc", "", 3));
	printf("%p\n", ft_strnstr("", "", 3));
	printf("%p\n", strnstr("", "", 3));
}