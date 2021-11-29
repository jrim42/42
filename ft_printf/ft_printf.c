/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:08:41 by jrim              #+#    #+#             */
/*   Updated: 2021/11/30 01:52:43 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *form, ...);
int	parse_form(char *form, va_list ap);
int	detect_type(t_detail *detail, va_list ap);

int ft_printf(const char *form, ...)
{
	va_list ap;
	int		printed_len;

	va_start(ap, form);
	printed_len = check_format((char *)form, ap);
	va_end(ap);
	return (printed_len);
}

int	parse_form(char *form, va_list ap)
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

int	detect_type(t_detail *detail, va_list ap)
{
	int		len_sum;
    char    type;
    
    len_sum = 0;
    type = detail->type;
    if (type == '%')
        len_sum += print_per(detail);
    else if (type == 'c')
        len_sum += print_char(detail, ap);
    else if (type == 's')
        len_sum += print_str(detail, ap);
    else if (type == 'x' || type == 'X' || type == 'p')
        len_sum += print_hex(detail, ap);
    else if (type == 'd' || type == 'i' || type == 'u')
        len_sum += print_int(detail, ap);
    else if (type == 'u')
        len_sum += print_uns(detail, ap);
	return (len_sum);
}
