/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 12:48:24 by jrim              #+#    #+#             */
/*   Updated: 2021/09/29 18:27:18 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*int2str(char *new_str, int num, char *base, int base_len);
int		char4str(int num, int base_len);
int		str2int(char *str, char *base, int base_len, int num);
int		is_in_base(char c, char *base);

char	*int2str(char *new_str, int num, char *base, int base_len)
{
	int	i;
	int	size;

	if (num == 0)
	{
		new_str[0] = base[0];
		new_str[1] = '\0';
		return (new_str);
	}
	i = 0;
	if (num < 0)
	{
		new_str[i] = '-';
		num *= -1;
		i++;
	}
	size = i + char4str(num, base_len);
	new_str[size--] = '\0';
	while (num > 0)
	{
		new_str[size] = base[num % base_len];
		num /= base_len;
		size--;
	}
	return (new_str);
}

int	char4str(int num, int base_len)
{
	int	size;

	size = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= base_len;
		size++;
	}
	return (size);
}

int	str2int(char *str, char *base, int base_len, int num)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (is_in_base(str[i], base) > base_len)
			return (num);
		if (is_in_base(str[i], base) < base_len)
			num += is_in_base(str[i], base);
		if (is_in_base(str[i + 1], base) < base_len)
			num *= base_len;
		i++;
	}
	return (num);
}

int	is_in_base(char c, char *base)
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
