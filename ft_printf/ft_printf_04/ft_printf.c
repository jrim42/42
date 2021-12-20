/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:08:41 by jrim              #+#    #+#             */
/*   Updated: 2021/12/20 00:14:03 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *form, ...);
void	init_detail(t_detail *detail);
int		parse_form(char *form, t_detail *detail, va_list ap);
int		check_type(char *form, t_detail *detail);

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
	detail->type = 0;
	detail->align = OFF;
	detail->pad = OFF;
	detail->prec = -1;
	detail->wid = OFF;
	detail->alt = OFF;
	detail->sign = OFF;
	detail->base = 10;
	detail->str_len = 0;
	detail->ret_len = 0;
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
			while ((ft_strchr(FLAG, *form) || ft_isdigit(*form)) && *form)
				form += parse_flag(form, detail, ap);
			if (check_type(form, detail))
				len += detect_type(detail, ap);
			else
				len += print_else(detail, *form);
			init_detail(detail);
			form++;
		}
	}
	return (len);
}

int	check_type(char *form, t_detail *detail)
{
	while (*form)
	{
		if (ft_strchr(TYPE, *form))
		{
			detail->type = *form;
			return (1);
		}
		form++;
	}
	return (0);
}