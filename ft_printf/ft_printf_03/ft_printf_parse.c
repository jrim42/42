/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:18:26 by jrim              #+#    #+#             */
/*   Updated: 2021/12/18 18:29:08 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_form(char *form, t_detail *detail, va_list ap);
int	parse_flag(char *form, t_detail *detail, va_list ap);
int	parse_prec(char *form, t_detail *detail, va_list ap);
int	parse_width(char *form, t_detail *detail, va_list ap);
int	detect_type(t_detail *detail, va_list ap);

int	parse_form(char *form, t_detail *detail, va_list ap)
{
	int			len;

	len = 0;
	while (*form != '\0')
	{
		while (*form != '%' && *form != '\0')
		{
			len++;
			write(1, form++, 1);
		}
		if (*form == '%')
		{
			form++;
			while (ft_strchr(TYPE, *form) == 0)
				form += parse_flag(form, detail, ap);
			if (ft_strchr(TYPE, *form) != 0)
			{
				detail->type = *form;
				len += detect_type(detail, ap);
			}
			init_detail(detail);
			form++;
		}
	}
	return (len);
}

int	parse_flag(char *form, t_detail *detail, va_list ap)
{
	int	form_len;

	form_len = 1;
	if (*form == '#')
		detail->alt = 2;
	else if (*form == '+')
		detail->sign = '+';
	else if (*form == ' ' && detail->sign == OFF)
		detail->sign = ' ';
	else if (*form == '0')
		detail->pad = ON;
	else if (*form == '-')
	{
		detail->align = LEFT;
		detail->pad = OFF;
	}
	else if (*form == '.')
		form_len += parse_prec(++form, detail, ap);
	else
		form_len += parse_width(form, detail, ap) - 1;
	return (form_len);
}

int	parse_width(char *form, t_detail *detail, va_list ap)
{
	int	flag_len;

	flag_len = 0;
	if (ft_isdigit(*form) == 1)
	{
		detail->wid = ft_atoi(form);
		flag_len += numlen_base(detail->wid, 10);
	}
	else if (*form == '*')
	{
		detail->wid = va_arg(ap, int);
		if (detail->wid < 0)
		{
			detail->align = LEFT;
			detail->pad = OFF;
		}
		detail->wid *= (detail->wid > 0) - (detail->wid < 0);
	}
	if (detail->align == OFF)
		detail->align = RIGHT;
	return (flag_len);
}

int	parse_prec(char *form, t_detail *detail, va_list ap)
{
	int	flag_len;

	flag_len = 0;
	if (*form == '*')
	{
		detail->prec = va_arg(ap, int);
		if (detail->prec < 0)
		{
			detail->prec = -1;
			return (1);
		}
	}
	else if (ft_isdigit(*form) == 0)
		detail->prec = 0;
	else
	{
		detail->prec = ft_atoi(form);
		flag_len += numlen_base(detail->prec, 10);
	}
	if (detail->align != LEFT)
		detail->align = RIGHT;
	if (detail->prec > 0)
		detail->pad = ON;
	return (flag_len);
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
		len += print_char(detail, ap);
	else if (type == 's')
		len += print_str(detail, ap);
	else if (type == 'x' || type == 'X')
		len += print_hex(detail, ap);
	else if (type == 'p')
	{
		detail->alt = 2;
		len += print_hex(detail, ap);
	}
	else if (type == 'd' || type == 'i')
		len += print_int(detail, ap);
	else if (type == 'u')
		len += print_uns(detail, ap);
	return (len);
}
