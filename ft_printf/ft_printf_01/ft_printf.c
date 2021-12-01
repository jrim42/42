/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:08:41 by jrim              #+#    #+#             */
/*   Updated: 2021/12/01 18:14:31 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *form, ...);
int	parse_form(char *form, va_list ap);
int	detect_type(t_detail *detail, va_list ap);

int	ft_printf(const char *form, ...)
{
	va_list	ap;
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
	t_detail	*detail;

	len = 0;
	idx = 0;
	detail = (t_detail *)malloc(1 * sizeof(t_detail));
    if (!detail)
        return (0);
	init_detail(detail);
	while (form[idx] != '\0')
	{
		if (form[idx] != '%')
		{
			len++;
			write(1, &form[idx], 1);
		}
		else if (form[idx] == '%' && ft_strchr(TYPE, form[idx + 1]) != 0)
		{
			detail->type = form[++idx];
			len += detect_type(detail, ap);
		}
		idx++;
	}
	free(detail);
	return (len);
}

int	detect_type(t_detail *detail, va_list ap)
{
	int		len;
	char	type;

	len = 0;
	type = detail->type;
	if (type == '%')
		len += print_per();
	else if (type == 'c')
		len += print_char(ap);
	else if (type == 's')
		len += print_str(ap);
	else if (type == 'x' || type == 'X' || type == 'p')
	{
		detail->base = 16;
		len += print_hex(detail, ap);
	}
	else if (type == 'd' || type == 'i')
		len += print_int(ap);
	else if (type == 'u')
		len += print_uns(ap);
	return (len);
}
