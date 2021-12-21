/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:08:41 by jrim              #+#    #+#             */
/*   Updated: 2021/12/21 15:00:20 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *form, ...);
int		parse_form(char *form, t_detail *detail, va_list ap);
void	init_detail(t_detail *detail);
void	check_type(char *form, t_detail *detail);
int		check_error(t_detail *detail);

int	ft_printf(const char *form, ...)
{
	va_list		ap;
	int			len;
	t_detail	*detail;

	va_start(ap, form);
	detail = (t_detail *)malloc(1 * sizeof(t_detail));
	if (!detail)
		return (0);
	len = parse_form((char *)form, detail, ap);
	va_end(ap);
	free(detail);
	return (len);
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
			while ((ft_strchr(FLAG, *form) || ft_isdigit(*form)) && *form)
				form += parse_flag(form, detail, ap);
			check_type(form, detail);
			if (check_error(detail) != 1)
				return (check_error(detail));
			len += detect_type(detail, ap);
			form++;
		}
	}
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

void	check_type(char *form, t_detail *detail)
{
	detail->type = *form;
	while (*form)
	{
		if (ft_strchr(TYPE, detail->type))
			return ;
		form++;
	}
	if (!ft_strchr(TYPE, detail->type) && detail->type)
		detail->str_len = 1;
}

int	check_error(t_detail *detail)
{
	if (detail->wid > 2147483646 || detail->wid < -2147483646)
	{
		if (!detail->type)
			return (0);
		else
			return (-1);
	}
	if (detail->prec > 2147483646)
	{
		if (!detail->type)
			return (0);
		else if (ft_strchr(TYPE, detail->type))
			return (-1);
		else
			detail->prec = -1;
	}
	return (1);
}
