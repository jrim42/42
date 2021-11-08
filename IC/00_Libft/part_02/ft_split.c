#include <stdlib.h>

int		count_str(char *str, char *charset);
void	make_strs(char **strs, int idx, char **ptr, char *charset);
int		is_sep(char ch, char *charset);

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	char	*ptr;
	int		idx;
	int		str_cnt;

	ptr = str;
	str_cnt = count_str(ptr, charset) + 1;
	strs = (char **)malloc(str_cnt * sizeof(char *));
	if (!(strs))
		return (0);
	idx = 0;
	while (idx < str_cnt - 1 && *ptr != '\0')
	{
		while (is_sep(*ptr, charset) == 1 && *ptr != '\0')
			ptr++;
		make_strs(strs, idx, &ptr, charset);
		idx++;
	}
	strs[idx] = 0;
	return (strs);
}

void	make_strs(char **strs, int idx, char **ptr, char *charset)
{
	int	len;

	len = 0;
	while (is_sep(*(*ptr + len), charset) == 0 && *(*ptr + len) != '\0')
		len++;
	strs[idx] = (char *)malloc((len + 1) * sizeof(char));
	if (!(strs[idx]))
		return ;
	len = 0;
	while (is_sep(**ptr, charset) == 0 && **ptr != '\0')
	{
		strs[idx][len] = **(ptr);
		len++;
		(*ptr)++;
	}
	strs[idx][len] = '\0';
}

int	count_str(char *ptr, char *charset)
{
	int	cnt;
	int	flag;

	cnt = 0;
	flag = 1;
	while (*ptr != '\0')
	{
		if (is_sep(*ptr, charset) == 1 && flag == 0)
			flag = 1;
		else if (is_sep(*ptr, charset) == 0 && flag == 1)
		{
			flag = 0;
			cnt++;
		}
		ptr++;
	}
	return (cnt);
}

int	is_sep(char ch, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (ch == charset[i])
			return (1);
		i++;
	}
	return (0);
}