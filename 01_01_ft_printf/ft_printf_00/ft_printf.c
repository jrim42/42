/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:08:41 by jrim              #+#    #+#             */
/*   Updated: 2021/12/06 20:42:50 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *form, ...);
void	init_detail(t_detail *detail);
int		parse_form(char *form, t_detail *detail, va_list ap);
int		detect_type(t_detail *detail, va_list ap);

int	ft_printf(const char *form, ...)
{
	va_list		ap;
	int			len;
	t_detail	*detail;

	va_start(ap, form);
	detail = (t_detail *)malloc(1 * sizeof(t_detail));
	if (!detail)
		return (0);
	init_detail(detail);
	len = parse_form((char *)form, detail, ap);
	va_end(ap);
	free(detail);
	return (len);
}

void	init_detail(t_detail *detail)
{
	detail->type = OFF;
	detail->sign = OFF;
	detail->alt = OFF;
	detail->base = 10;
}

int	parse_form(char *form, t_detail *detail, va_list ap)
{
	int			len;

	len = 0;
	while (*form != '\0')
	{
		while (*form != '%' && *form)
		{
			len++;
			write(1, form++, 1);
		}
		if (*form == '%')
		{
			form++;
			init_detail(detail);
			if (ft_strchr(TYPE, *form))
			{
				detail->type = *form;
				len += detect_type(detail, ap);
			}
			else
				len += print_str(detail, *form, 0);
			form++;
		}
	}
	return (len);
}

int	detect_type(t_detail *detail, va_list ap)
{
	int		len;
	char	type;

	len = 0;
	type = detail->type;
	if (type == '%' || type == 'c' || type == 's')
		len += parse_str(detail, ap);
	else if (type == 'd' || type == 'i' || type == 'u')
		len += parse_int(detail, ap);
	else if (type == 'x' || type == 'X' || type == 'p')
		len += parse_hex(detail, ap);
	return (len);
}