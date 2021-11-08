#include <stdlib.h>

int		ft_strlen(char *str);
char	*ft_strcat(char *dest, char *src);
char	*ft_malloc_str(int size, char **strs, char **new_str, char *sep);

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		idx;
	char	*new_str;

	if (size == 0)
	{
		new_str = (char *)malloc(1 * sizeof(char));
		return (new_str);
	}
	else
		new_str = ft_malloc_str(size, strs, &new_str, sep);
	idx = 0;
	new_str[0] = '\0';
	while (idx < size)
	{
		new_str = ft_strcat(new_str, strs[idx]);
		if (idx < size - 1)
			new_str = ft_strcat(new_str, sep);
		idx++;
	}
	return (new_str);
}

char	*ft_strcat(char *dest, char *src)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_malloc_str(int size, char **strs, char **new_str, char *sep)
{
	int	total_len;
	int	sep_len;
	int	strs_len;
	int	i;

	strs_len = 0;
	sep_len = ft_strlen(sep);
	i = 0;
	while (i < size)
	{
		strs_len += ft_strlen(strs[i]);
		i++;
	}
	total_len = strs_len + sep_len * (size - 1) + 1;
	*new_str = (char *)malloc(total_len * sizeof(char));
	if (!(*new_str))
		return (0);
	return (*new_str);
}