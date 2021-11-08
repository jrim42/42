#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		src_len;
	int		i;
	char	*dupstr;

	src_len = ft_strlen(src);
	dupstr = (char *)malloc((src_len + 1) * sizeof(char));
	if (!(dupstr))
		return (0);
	i = 0;
	while (i < src_len)
	{
		dupstr[i] = src[i];
		i++;
	}
	dupstr[src_len] = '\0';
	return (dupstr);
}