/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:08:41 by jrim              #+#    #+#             */
/*   Updated: 2021/11/25 16:08:43 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	specify_forms(const char **str, va_list ap);

int ft_printf(const char *str, ...)
{
    va_list ap;
	int		len;

	va_start(ap, str);
	len = ft_strlen(str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			len += specify_forms(&str, ap) - 2;
		}
		else
		{
			write(1, str, 1);
			str++;
		}
	}
	va_end(ap);
	return (len);
}

int	specify_forms(const char **str, va_list ap)
{
	int		i;
    char    *str_ptr;

    str_ptr = (char *)*str;
	while (**str)
	{
		if (*str_ptr == 'c')
			return (print_char(str, ap));
		else if (*str_ptr == 's')
			return (print_str(str, ap));
		else if (*str_ptr == 'x' || *str_ptr == 'X' || *str_ptr == 'p')
			return (print_hex(str, ap));
		else if (*str_ptr == 'd' || *str_ptr == 'i' || *str_ptr == 'u')
			return (print_int(str, ap));
		else if (*str_ptr == 'u')
			return (print_uns(str, ap));
		else
			return (print_per(str));
	}
	return (0);
}
