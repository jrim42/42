/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 19:06:03 by jrim              #+#    #+#             */
/*   Updated: 2021/09/25 12:09:39 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_space_or_sign(char *str, int *sign)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			(*sign) *= -1;
		i++;
	}
	return (i);
}

int	is_base_valid(char *base, int base_len)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 1;
	if (base_len <= 1)
		return (0);
	while (i < base_len - 1)
	{
		if (ft_is_space_or_sign(base + i, &k) > 0)
			return (0);
		j = i + 1;
		while (j < base_len)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (ft_is_space_or_sign(base + i, &k) > 0)
		return (0);
	return (1);
}

int	is_char_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (i + 1);
}

int	str2int(char *str, char *base, int len, int num)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && is_char_in_base(str[i], base) < len)
	{
		if (is_char_in_base(str[i], base) > len)
			return (num);
		if (is_char_in_base(str[i], base) < len)
			num += is_char_in_base(str[i], base);
		if (is_char_in_base(str[i + 1], base) < len)
			num *= len;
		i++;
	}
	return (num);
}

int	ft_atoi_base(char *str, char *base)
{
	int				len;
	unsigned int	num;
	int				sign;

	len = 0;
	sign = 1;
	while (base[len] != '\0')
		len++;
	if (is_base_valid(base, len) == 0)
		return (0);
	str += ft_is_space_or_sign(str, &sign);
	num = str2int(str, base, len, 0);
	return ((int)num * sign);
}
