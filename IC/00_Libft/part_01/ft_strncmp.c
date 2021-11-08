int	ft_strncmp(char	*s1, char *s2, unsigned int n)
{
	unsigned int	idx;

	idx = 0;
	while ((s1[idx] != '\0' || s2[idx] != '\0') && idx < n)
	{
		if (s1[idx] < s2[idx])
			return (-1);
		else if (s1[idx] > s2[idx])
			return (1);
		idx++;
	}
	return (0);
}