#include "libft.h"

char	*ft_strcat(char *dst, char *src);

char    *ft_strjoin(char const *s1, char const *s2)
{
	int		idx;
	int		total_len;
	char	*new_str;

	idx = 0;
	total_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	new_str = (char *)malloc(total_len * sizeof(char));
	new_str[0] = '\0';
	ft_strcat(s1, s2);
	return (new_str);
}

char	*ft_strcat(char *dst, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dst[i] != '\0')
		i++;
	while (src[j] != '\0')
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (dst);
}