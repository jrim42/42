/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:17:04 by jrim              #+#    #+#             */
/*   Updated: 2021/12/01 18:20:14 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(va_list ap);
int	print_str(va_list ap);
int	print_per(void);

int	print_char(va_list ap)
{
	int	ch;

	ch = va_arg(ap, int);
	write(1, &ch, 1);
	return (1);
}

int	print_str(va_list ap)
{
	const char	*str;
	size_t		len;

	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}

int	print_per(void)
{
	write(1, "%", 1);
	return (1);
}
