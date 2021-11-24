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

char	*ft_strchr(const char *s, int c)
{
	size_t	idx;
	size_t	s_len;
	char	*ptr;

	if (!s)
		return (0);
	idx = 0;
	s_len = ft_strlen(s) + 1;
	ptr = (char *)s;
	while (idx < s_len)
	{
		if (*ptr == (char)c)
			return (ptr);
		idx++;
		ptr++;
	}
	return (0);
}

int main(void)
{
    int     eol_idx;
    char    *str;

    str = (char *)malloc(11 * sizeof(char));
    for (int i = 0; i < 9; i++)
        str[i] = 'a';
    str[9] = '\n';
    str[10] = '\0';
    eol_idx = (int)(ft_strchr(str, '\n') - str);
    printf("%d\n", eol_idx);
}