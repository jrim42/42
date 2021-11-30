/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:08:41 by jrim              #+#    #+#             */
/*   Updated: 2021/11/30 22:29:50 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *form, ...);
int	parse_form(char *form, va_list ap);
int	detect_type(char type, va_list ap);

int	main(void)
{
	int	len;

	len = ft_printf("fxxking ft_printf\n");
	ft_printf("%d\n", len);
	len = ft_printf("%u %d\n", 123, -123);
	ft_printf("%d\n", len);
	len = ft_printf("%c%c\n", '4', '2');
	ft_printf("%d\n", len);
	len = ft_printf("%s %s\n", "(not null)", 0);
	ft_printf("%d\n", len);
	len = ft_printf("%x = %X\n", 255, 255);
	ft_printf("%d\n", len);
}

int ft_printf(const char *form, ...)
{
	va_list ap;
	int		len;

	va_start(ap, form);
	len = parse_form((char *)form, ap);
	va_end(ap);
	return (len);
}

int	parse_form(char *form, va_list ap)
{
	int			len;
	int			idx;

	len = 0;
	idx = 0;
	while (form[idx] != '\0')
	{
		if (form[idx] != '%')
		{
			len++;
			write(1, &form[idx], 1);
		}
		else if (form[idx] == '%' && ft_strchr(TYPE, form[idx + 1]) != 0)
			len += detect_type(form[++idx], ap);
		idx++;
	}
	return (len);
}

int	detect_type(char type, va_list ap)
{
	int		len;
    
    len = 0;
    if (type == '%')
        len += print_per();
    else if (type == 'c')
        len += print_char(ap);
    else if (type == 's')
        len += print_str(ap);
    else if (type == 'x' || type == 'X' || type == 'p')
        len += print_hex(type, ap);
    else if (type == 'd' || type == 'i')
        len += print_int(ap);
    else if (type == 'u')
        len += print_uns(ap);
	return (len);
}
