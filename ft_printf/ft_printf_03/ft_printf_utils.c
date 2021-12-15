/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:28:09 by jrim              #+#    #+#             */
/*   Updated: 2021/12/14 19:13:01 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_width(t_detail *detail, int cnt, int pad);
void	fill_prec(t_detail *detail, int cnt, int ret_len, int pad);
void	print_alt(t_detail *detail);
char	*ft_itoa_base(t_detail *detail, unsigned long num, char *base);
size_t	numlen_base(unsigned long num, size_t base_len);

void	fill_width(t_detail *detail, int cnt, int pad)
{
	if (detail->type != 'c' && detail->type != 's' && detail->prec == -1)
	{
		if (detail->align == RIGHT && detail->sign != OFF)
			return ;
		else if (detail->align == RIGHT && detail->alt != OFF && detail->pad == ON)
			return ;
		else if (detail->pad == ON)
			pad = 1;
	}
	if (pad == 1)
		while (cnt-- > 0)
			write(1, "0", 1);
	else
		while (cnt-- > 0)
			write(1, " ", 1);
}

void	fill_prec(t_detail *detail, int cnt, int ret_len, int pad)
{
	if ((detail->sign != OFF || detail->alt != OFF) && detail->prec == -1)
		cnt = detail->wid - ret_len;
	if (pad == 1)
		while (cnt-- > 0)
			write(1, "0", 1);
}

void	print_alt(t_detail *detail)
{
	if (detail->alt == 2)
	{
		if (detail->type == 'X')
			write(1, "0X", 2);
		else if (detail->type == 'x' || detail->type == 'p')
			write(1, "0x", 2);
	}
}

char	*ft_itoa_base(t_detail *detail, unsigned long num, char *base)
{
	size_t	base_len;
	size_t	idx;
	char	*str;

	if (detail->type != 'p' && num == 0)
		detail->alt = OFF;
	base_len = detail->base;
	idx = numlen_base(num, base_len) + 1;
	str = (char *)malloc(idx * sizeof(char));
	if (!str)
		return (0);
	str[0] = '0';
	str[--idx] = '\0';
	while (idx-- > 0 && num > 0)
	{
		str[idx] = base[num % base_len];
		num /= base_len;
	}
	if (detail->type == 'X')
		while (str[++idx])
			str[idx] = ft_toupper(str[idx]);
	return (str);
}

size_t	numlen_base(unsigned long num, size_t base_len)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		len++;
		num /= base_len;
	}
	return (len);
}
