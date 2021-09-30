/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 13:00:28 by jrim              #+#    #+#             */
/*   Updated: 2021/09/29 18:26:01 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
int		ft_is_space_or_sign(char *str, int *sign);
int		is_base_valid(char *base, int base_len);
int		str2int(char *str, char *base, int base_len, int num);
char	*int2str(char *new_str, int num, char *base, int base_len);
int		ft_strlen(char *str);
int		char4str(int num, int base_len);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		sign;
	int		num;
	int		size;
	char	*ptr;
	char	*new_str;

	if (is_base_valid(base_from, ft_strlen(base_from)) == 0 \
			|| is_base_valid(base_to, ft_strlen(base_to)) == 0)
		return (0);
	sign = 1;
	ptr = nbr;
	ptr += ft_is_space_or_sign(nbr, &sign);
	num = str2int(ptr, base_from, ft_strlen(base_from), 0);
	size = char4str(num, ft_strlen(base_to));
	if (sign < 0)
		new_str = (char *)malloc((size + 2) * sizeof(char));
	else
		new_str = (char *)malloc((size + 1) * sizeof(char));
	if (!(new_str))
		return (0);
	new_str = int2str(new_str, num * sign, base_to, ft_strlen(base_to));
	return (new_str);
}

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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
