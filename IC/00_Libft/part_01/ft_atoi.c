int	ft_isspace(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	return (i);
}

int	ft_is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else
		return (10);
}

int	ft_atoi(char *str)
{
	int					i;
	unsigned int		num;
	int					sign;
	char				*ptr;

	i = 0;
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
	while (ft_is_num(*ptr) != 10 && *ptr != '\0')
	{
		num += ft_is_num(*ptr);
		if (ft_is_num(*(ptr + 1)) != 10 && *(ptr + 1) != '\0')
			num *= 10;
		ptr++;
	}
	return ((int)num * sign);
}