/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:28:09 by jrim              #+#    #+#             */
/*   Updated: 2021/12/21 21:21:15 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_width(t_detail *detail, int cnt, int pad);
void	fill_prec(t_detail *detail, int pad);
void	print_sign(t_detail *detail);
char	*ft_itoa_base(t_detail *detail, unsigned long num, char *base);
int		numlen_base(unsigned long num, int base_len);

void	fill_width(t_detail *detail, int cnt, int pad)
{
	if (ft_strchr("pdiuxX", detail->type) && detail->prec == -1)
	{
		if (detail->align == RIGHT && detail->pad == ON
			&& (detail->sign != OFF || detail->alt != OFF))
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

void	fill_prec(t_detail *detail, int pad)
{
	int	cnt;

	cnt = detail->prec - detail->str_len;
	if (detail->prec != -1)
		pad = 1;
	else if (detail->align == RIGHT && detail->pad == ON
		&& (detail->sign != OFF || detail->alt != OFF))
		cnt = detail->wid - detail->ret_len;
	if (pad == 1)
		while (cnt-- > 0)
			write(1, "0", 1);
}

void	print_sign(t_detail *detail)
{
	if (detail->sign != OFF)
		write(1, &detail->sign, 1);
	else if (detail->alt == 2)
	{
		if (detail->type == 'X')
			write(1, "0X", 2);
		else if (detail->type == 'x' || detail->type == 'p')
			write(1, "0x", 2);
	}
}

char	*ft_itoa_base(t_detail *detail, unsigned long num, char *base)
{
	int		base_len;
	int		idx;
	char	*str;

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

int	numlen_base(unsigned long num, int base_len)
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
