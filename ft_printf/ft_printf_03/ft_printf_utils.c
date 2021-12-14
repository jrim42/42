/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:28:09 by jrim              #+#    #+#             */
/*   Updated: 2021/12/14 18:11:10 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_str(int cnt, int pad);
void	print_alt(t_detail *detail);
void	print_sign(t_detail *detail);
int		parse_numlen(t_detail *detail, int *str_len);
int		parse_strlen(t_detail *detail, int *str_len);

void	fill_str(int cnt, int pad)
{
	if (pad == 1)
		while (cnt-- > 0)
			write(1, "0", 1);
	else
		while (cnt-- > 0)
			write(1, " ", 1);
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

void	print_sign(t_detail *detail)
{
	if (detail->sign != OFF)
		write(1, &detail->sign, 1);
}

int	parse_numlen(t_detail *detail, int *str_len)
{
	int		ret_len;

	ret_len = *str_len;
	if (detail->prec != -1 && detail->prec > *str_len)
		ret_len = detail->prec;
	if (detail->type == 'p' || detail->type == 'x' || detail->type == 'X')
	{
		ret_len += detail->alt;
		*str_len += detail->alt;
	}
	else if (detail->type == 'd' || detail->type == 'i')
		if (detail->sign != OFF)
		{
			ret_len += 1;
			*str_len += 1;
		}
	return (ret_len);
}

int	parse_strlen(t_detail *detail, int *str_len)
{
	int	ret_len;

	if (detail->type == 's')
		if (detail->prec != -1 && detail->prec < *str_len)
			*str_len = detail->prec;
	ret_len = *str_len;
	if (ret_len < detail->wid)
		ret_len = detail->wid;
	return (ret_len);
}
