/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:17:04 by jrim              #+#    #+#             */
/*   Updated: 2021/12/10 17:12:49 by jrim             ###   ########.fr       */
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
	if (detail->align != RIGHT)
		write(1, &ch, 1);
	print_width(detail, 1, ret_len);
	if (detail->align == RIGHT)
		write(1, &ch, 1);
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
	if (detail->align != RIGHT)
		write(1, str, str_len);
	print_width(detail, str_len, ret_len);
	if (detail->align == RIGHT)
		write(1, str, str_len);
	return (ret_len);
}

int	print_per(void)
{
	write(1, "%", 1);
	return (1);
}
