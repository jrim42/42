#include "libft.h"

int		count_str(char const *s, char c);
void	make_strs(char **strs, int idx, char **ptr, char c);

char    **ft_split(char const *s, char c)
{
	char	**strs;
	char	*ptr;
	int		idx;
	int		str_cnt;

	ptr = s;
	str_cnt = count_str(s, c) + 1;
	strs = (char **)malloc(str_cnt * sizeof(char *));
	if (!(strs))
		return (0);
	idx = 0;
	while (idx < str_cnt - 1 && *ptr != '\0')
	{
		while (*ptr == c && *ptr != '\0')
			ptr++;
		make_strs(strs, idx, &ptr, c);
		idx++;
	}
	strs[idx] = 0;
	return (strs);
}

int	count_str(char const *s, char c)
{
	int	idx;
	int	cnt;

	idx = 0;
	cnt = 0;
	while (s[idx] != '\0')
	{
		if (s[idx] == c)
			cnt++;
		idx++;
	}
	return (cnt);
}

void	make_strs(char **strs, int idx, char **ptr, char c)
{
	int	len;

	len = 0;
	while (*(*ptr + len) == c && *(*ptr + len) != '\0')
		len++;
	strs[idx] = (char *)malloc((len + 1) * sizeof(char));
	if (!(strs[idx]))
		return ;
	len = 0;
	while (**ptr == c && **ptr != '\0')
	{
		strs[idx][len] = **(ptr);
		len++;
		(*ptr)++;
	}
	strs[idx][len] = '\0';
}