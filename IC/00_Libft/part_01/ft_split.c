#include "libft.h"

int		count_str(char const *s, char c);
void	make_strs(char **strs, int idx, char **ptr, char c);

char    **ft_split(char const *s, char c)
{
	char	**strs;
	char	*ptr;
	int		idx;
	int		str_cnt;

	ptr = (char *)s;
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
	int	flag;

	idx = 0;
	cnt = 0;
	flag = 1;
	while (s[idx] != '\0')
	{
		if (s[idx] != c && flag == 1)
		{
			cnt++;
			flag = 0;
		}
		else if (s[idx] == c && flag == 0)
			flag = 1;
		idx++;
	}
	return (cnt);
}

void	make_strs(char **strs, int idx, char **ptr, char c)
{
	int	len;

	len = 0;
	while ((*ptr)[len] != c && (*ptr)[len] != '\0')
		len++;
	strs[idx] = (char *)malloc((len + 1) * sizeof(char));
	if (!(strs[idx]))
	{
		while (idx-- > 0)
			free (strs[idx]);
		free (strs);
		return ;
	}
	len = 0;
	while (**ptr != c && **ptr != '\0')
	{
		strs[idx][len] = **(ptr);
		len++;
		(*ptr)++;
	}
	strs[idx][len] = '\0';
}

int	main(void)
{
	char	**strs;
	int		idx;

    strs = ft_split("1  2 34 56 78 ", ' ');
	idx = 0;
    while (strs[idx])
        printf("%s\n", strs[idx++]);
	return (0);
}