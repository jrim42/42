#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

    if (!s)
        return (0);
	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	idx;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	idx = 0;
	if (dst_len + 1 > dstsize)
		return (src_len + dstsize);
	while (src[idx] != '\0' && dst_len + idx + 1 < dstsize)
	{
		dst[dst_len + idx] = src[idx];
		idx++;
	}
	dst[dst_len + idx] = '\0';
	return (dst_len + src_len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	idx;
	size_t	total_len;
	char	*new_str;

	idx = 0;
	if (!(s2))
		return ((char *)s1);
	total_len = ft_strlen(s1) + ft_strlen(s2) + 1;
    printf("%zu\n", total_len);
	new_str = (char *)malloc(total_len * sizeof(char));
	if (!new_str)
		return (0);
    printf("malloc success\n");
	new_str[0] = '\0';
	ft_strlcat(new_str, (char *)s1, ft_strlen(s1) + 1);
	ft_strlcat(new_str, (char *)s2, total_len);
	return (new_str);
}

int main(void)
{
    char    *str[10];

    printf("%s\n", str[0]);
    str[0] = ft_strjoin(str[0], "123");
    printf("%s\n", str[0]);
}