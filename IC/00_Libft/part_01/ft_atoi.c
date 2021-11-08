#include "libft.h"

int	ft_isspace(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] == ' ' || str[idx] == '\f' || str[idx] == '\n'
		|| str[idx] == '\r' || str[idx] == '\t' || str[idx] == '\v')
		idx++;
	return (idx);
}

int	ft_atoi(const char *str)
{
	unsigned int		num;
	int					sign;
	char				*ptr;

	num = 0;
	sign = 1;
	ptr = str;
	ptr += ft_isspace(str);
	while (*ptr == '+' || *ptr == '-')
	{
		if (*ptr == '-')
			sign *= (-1);
		ptr++;
	}
	while (ft_isdigit(*ptr) == 1 && *ptr != '\0')
	{
		num += (*ptr) - '0';
		if (ft_isdigit(*(ptr + 1)) == 1 && *(ptr + 1) != '\0')
			num *= 10;
		ptr++;
	}
	return ((int)num * sign);
}