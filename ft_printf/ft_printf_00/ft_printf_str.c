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

int		parse_str(t_detail *detail, va_list ap);
int		print_str(t_detail *detail, int ch, const char *str);

int	parse_str(t_detail *detail, va_list ap)
{
	int			ch;
	const char	*str;
	int			len;

	ch = 0;
	str = 0;
	if (detail->type == 'c')
		ch = va_arg(ap, int);
	else if (detail->type == '%')
		ch = '%';
	else if (detail->type == 's')
	{
		str = va_arg(ap, char *);
		if (!str)
			str = "(null)";
	}
	len = print_str(detail, ch, str);
	return (len);
}

int	print_str(t_detail *detail, int ch, const char *str)
{
	int	len;
	
	if (detail->type == 's')
	{
		len = ft_strlen(str);
		write(1, str, len);
	}
	else
	{
		len = 1;
		write(1, &ch, len);
	}
	return (len);
}
