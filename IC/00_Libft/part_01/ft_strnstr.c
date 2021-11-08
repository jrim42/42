int	ft_strcmp(char	*s1, char *s2)
{
	int	idx;

	idx = 0;
	while (s1[idx] != '\0' || s2[idx] != '\0')
	{
		if (s1[idx] < s2[idx])
			return (-1);
		else if (s1[idx] > s2[idx])
			return (1);
		idx++;
	}
	return (0);
}

char    *ft_strnstr(const char *haystack, const char *needle, unsigned int len)
{
    int     idx;
    char    *ptr;

    idx = 0;
    ptr = haystack;
    if (!haystack && !needle)
		return (haystack);
	while (idx <= len)
	{
		if (ft_strcmp(ptr, needle) == 0)
			return (ptr);
		idx++;
		ptr++;
	}
	return (0);
}