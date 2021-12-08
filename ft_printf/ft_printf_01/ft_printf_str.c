/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:17:04 by jrim              #+#    #+#             */
/*   Updated: 2021/12/08 21:00:14 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(t_detail *detail, va_list ap);
int	print_str(t_detail *detail, va_list ap);
int	print_per(void);

int	print_char(t_detail *detail, va_list ap)
{
	int	ch;
	int	len;

	ch = va_arg(ap, int);
	len = 1;
	if (1 < detail->wid)
		len = detail->wid;
	if (detail->align == LEFT)
		write(1, &ch, 1);
	print_width(detail, 1);
	if (detail->align == RIGHT)
		write(1, &ch, 1);
	return (len);
}

int	print_str(t_detail *detail, va_list ap)
{
	const char	*str;
	int			len;

	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (len < detail->wid)
		len = detail->wid;
	if (detail->align == LEFT)
		write(1, str, ft_strlen(str));
	print_width(detail, ft_strlen(str));
	if (detail->align == RIGHT)
		write(1, str, ft_strlen(str));
	return (len);
}

int	print_per(void)
{
	write(1, "%", 1);
	return (1);
}
