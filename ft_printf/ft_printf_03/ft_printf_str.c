/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:17:04 by jrim              #+#    #+#             */
/*   Updated: 2021/12/14 17:41:44 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(t_detail *detail, va_list ap);
int	print_str(t_detail *detail, va_list ap);
int	print_per(void);

int	print_char(t_detail *detail, va_list ap)
{
	int	ch;
	int	str_len;
	int	ret_len;

	ch = va_arg(ap, int);
	str_len = 1;
	ret_len = parse_strlen(detail, &str_len);
	if (detail->align == RIGHT)
		fill_str(detail, ret_len - 1, 0);
	write(1, &ch, 1);
	if (detail->align != RIGHT)
		fill_str(detail, ret_len - 1, 0);
	return (ret_len);
}

int	print_str(t_detail *detail, va_list ap)
{
	const char	*str;
	int			str_len;
	int			ret_len;

	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	str_len = ft_strlen(str);
	ret_len = parse_strlen(detail, &str_len);
	// printf("wid : %d\n", detail->wid);
	// printf("prec : %d\n", detail->prec);
	// printf("str : %d\n", str_len);
	if (detail->align == RIGHT)
		fill_str(detail, ret_len - str_len, 0);
	write(1, str, str_len);
	if (detail->align != RIGHT)
		fill_str(detail, ret_len - str_len, 0);
	return (ret_len);
}

int	print_per(void)
{
	write(1, "%", 1);
	return (1);
}
