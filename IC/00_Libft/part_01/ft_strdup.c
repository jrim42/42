#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		src_len;
	int		idx;
	char	*dupstr;

	src_len = ft_strlen(s1);
	dupstr = (char *)malloc((src_len + 1) * sizeof(char));
	if (!(dupstr))
		return (0);
	idx = 0;
	while (idx < src_len)
	{
		dupstr[idx] = s1[idx];
		idx++;
	}
	dupstr[src_len] = '\0';
	return (dupstr);
}