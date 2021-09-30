/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 09:41:49 by jrim              #+#    #+#             */
/*   Updated: 2021/09/27 09:36:58 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_dec2hex(unsigned char c)
{
	int		dec;

	dec = c;
	write(1, &"0123456789abcdef"[dec / 16], 1);
	write(1, &"0123456789abcdef"[dec % 16], 1);
}

void	ft_print_addr(char *addr)
{
	long long	addr_dec;
	int			i;
	char		addr_hex[16];

	i = 0;
	addr_dec = (long long)addr;
	while (i < 16)
	{
		addr_hex[i++] = "0123456789abcdef"[addr_dec % 16];
		addr_dec /= 16;
	}
	while (i > 0)
		write(1, &addr_hex[--i], 1);
	write(1, ": ", 2);
}

void	ft_display_hex(void *addr, int len)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)addr;
	while (i < len)
	{
		ft_dec2hex(str[i]);
		if (i % 2 == 1)
			write(1, " ", 1);
		i++;
	}
	if (len < 16)
	{
		i = 40 - (len * 2 + len / 2);
		while (i-- > 0)
			write(1, " ", 1);
	}
}

void	ft_putstr(void *addr, int len)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)addr;
	while (i < len)
	{
		if (str[i] < 32 | str[i] > 126)
			str[i] = '.';
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	len;

	len = 0;
	if (size == 0)
		return (addr);
	while (len <= size)
	{
		ft_print_addr(addr + len);
		if (size - len >= 16)
		{
			ft_display_hex(addr + len, 16);
			ft_putstr(addr + len, 16);
		}
		else
		{
			ft_display_hex(addr + len, size - len);
			ft_putstr(addr + len, size - len);
		}
		len += 16;
	}
	return (addr);
}
