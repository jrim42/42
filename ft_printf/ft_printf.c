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

int ft_printf(const char *form, ...);
int	check_format(char *form, va_list ap);
int	detect_type(char *form, va_list ap);

int ft_printf(const char *form, ...)
{
	va_list arg_ptr;
	int		len;

	va_start(arg_ptr, form);
	len = check_format((char *)form, arg_ptr);
	va_end(arg_ptr);
	return (len);
}

int	check_format(char *form, va_list ap)
{
	int		return_len;
	int		idx;
	char	*detail;

	return_len = 0;
	while (form[idx] != '\0')
	{
		while (form[idx] != '%' && form[idx] != '\0')
		{
			return_len++;
			write(1, &form[idx++], 1);
		}
		while (form[idx] != '\0' && ft_strchr(TYPE, form[idx]) != 0)
		{
			 
		}
	}
}

int	detect_type(char *str, va_list arg_ptr)
{
	while (*str)
	{
		if (*str == 'c')
			return (print_char(str, arg_ptr));
		else if (*str == 's')
			return (print_str(str, arg_ptr));
		else if (*str == 'x' || *str == 'X' || *str == 'p')
			return (print_hex(str, arg_ptr));
		else if (*str == 'd' || *str == 'i' || *str == 'u')
			return (print_int(str, arg_ptr));
		else if (*str == 'u')
			return (print_uns(str, arg_ptr));
		else
			return (print_per(str));
	}
	return (0);
}
