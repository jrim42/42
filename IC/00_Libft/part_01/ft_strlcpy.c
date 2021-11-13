#include "libft.h"
#include <string.h>

size_t	ft_strlcpy(char *restrict dst, char *restrict src, size_t dstsize)
{
	unsigned int	src_len;
	unsigned int	idx;

	src_len = ft_strlen(src);
	idx = 0;
	if (dstsize > 0)
	{
		while (src[idx] != '\0' && idx + 1 < dstsize)
		{
			dst[idx] = src[idx];
			idx++;
		}
		dst[idx] = '\0';
	}
	return (src_len);
}

int	main(void)
{
	char	dst_1[20];
	char	dst_2[5];

	printf("%zu\n", ft_strlcpy(dst_1, "abc", 10));
	printf("%lu\n", strlcpy(dst_1, "abc", 10));
	printf("%zu\n", ft_strlcpy(dst_1, "abcd", 3));
	printf("%s\n", dst_1);
	printf("%lu\n", strlcpy(dst_1, "abcd", 3));
	printf("%zu\n", ft_strlcpy(dst_2, "abcd", 3));
	printf("%lu\n", strlcpy(dst_2, "abcd", 3));
	printf("%zu\n", ft_strlcpy(dst_2, "abcdef", 5));
	printf("%lu\n", strlcpy(dst_2, "abcdef", 5));
	printf("%s\n", dst_2);
}