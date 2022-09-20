#include "minirt.h"

void	ft_tblclear(char ***tbl)
{
	char	**cp;

	if (*tbl)
	{
		cp = *tbl;
		while (*cp)
			free(*cp++);
		free(*tbl);
		*tbl = NULL;
	}
}

int	ft_gnl_without_newline(int fd, char **line)
{
	int		ret;
	size_t	len;

	ret = ft_get_next_line(fd, line);
	if (ret <= 0)
		return (ret);
	len = 0U;
	if (*line)
		len = ft_strlen(*line);
	if (len && (*line)[len - 1] == '\n')
		(*line)[len - 1] = '\0';
	return (ret);
}

bool	ft_check_strtoi_iter(\
		const char *str, const int *limit, int *dst, size_t cnt)
{
	size_t	i;
	int		n;
	char	*endptr;

	if (!str || !dst || !cnt)
		return (false);
	i = 0U;
	while (i < cnt)
	{
		n = ft_strtoi(str, &endptr, 10);
		if (str == endptr)
			return (false);
		if (limit && (n < limit[LOWER_LIMIT] || n > limit[UPPER_LIMIT]))
			return (false);
		if (',' == *endptr)
			str = endptr + 1;
		*(dst + i) = n;
		i++;
	}
	if (*endptr)
		return (false);
	return (true);
}

bool	ft_check_strtod_iter(\
		const char *str, const double *limit, double *dst, size_t cnt)
{
	size_t	i;
	double	n;
	char	*endptr;

	if (!str || !dst || !cnt)
		return (false);
	i = 0U;
	while (i < cnt)
	{
		n = ft_strtod(str, &endptr);
		if (str == endptr)
			return (false);
		if (limit && (n < limit[LOWER_LIMIT] || n > limit[UPPER_LIMIT]))
			return (false);
		if (',' == *endptr)
			str = endptr + 1;
		*(dst + i) = n;
		i++;
	}
	if (*endptr)
		return (false);
	return (true);
}
