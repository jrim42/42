#include "gnl_00/get_next_line.h"

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

char	*ft_strdup(const char *s1)
{
	unsigned int	idx;
	unsigned int	src_len;
	char			*dupstr;

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
	dupstr[idx] = '\0';
	system("leaks a.out > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");
	return (dupstr);
}

int main(void)
{
    char    *buf;
    char    *dup_buf;

    buf = 0;
    buf = (char *)malloc(11 * sizeof(char));
    for (int i = 0; i < 10; i++)
        *(buf + i) = 'a';
    dup_buf = ft_strdup(buf);
    free(buf);
    return (0);
}
