/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:18:26 by jrim              #+#    #+#             */
/*   Updated: 2021/12/06 20:43:28 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_form(char *form, va_list ap);
int	parse_flag(char *form, t_detail *detail);
int	parse_width(char *form, t_detail *detail);
int	parse_prec(char *form, t_detail *detail);
int	detect_type(t_detail *detail, va_list ap);

int	parse_form(char *form, va_list ap)
{
	int			len;
	t_detail	*detail;

	len = 0;
	detail = (t_detail *)malloc(1 * sizeof(t_detail));
	if (!detail)
		return (0);
	init_detail(detail);
	while (*form != '\0')
	{
		if (*form != '%')
		{
			len++;
			write(1, form, 1);
		}
		if (*form == '%')
		{
			form++;
			while (ft_strchr(TYPE, *form) == 0)
				form += parse_flag(form, detail);
			if (ft_strchr(TYPE, *form) != 0)
			{
				detail->type = *form;
				len += detect_type(detail, ap);
			}
		}
		form++;
	}
	free(detail);
	return (len);
}

int	parse_flag(char *form, t_detail *detail)
{
	int	form_len;

	form_len = 0;
	if (*form == '#')
	{
		form_len++;
		detail->alt = 2;
	}
	else if (*form == '+')
	{
		form_len++;
		detail->plus = ON;
	}
	else if (*form == ' ')
	{
		form_len++;
		detail->sp = ON;
	}
	else 
		form_len += parse_width(form, detail);
	return (form_len);
}

int	parse_width(char *form, t_detail *detail)
{
	int	flag_len;

	flag_len = 0;
	if (*form == '0')
	{
		detail->wid = ft_atoi(++form);
		detail->align = RIGHT;
		detail->pad = ON;
		flag_len++;
	}
	else if (ft_isdigit(*form) == 1 || *form == '-')
	{
		detail->wid = ft_atoi(form);
		detail->align = RIGHT;
	}
	if (detail->wid < 0)
	{
		detail->wid *= -1;
		detail->align = LEFT;
		flag_len++;
	}
	flag_len += numlen_base(detail->wid, 10);
	if (*form == '-' && *(form + 1) == '0')
		flag_len++;
	return (flag_len);
}

int	parse_prec(char *form, t_detail *detail)
{
	detail->prec = 0;
	if (form)
		return (0);
	return (0);
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
	else if (type == 'x' || type == 'X' || type == 'p')
		len += print_hex(detail, ap);
	else if (type == 'd' || type == 'i')
		len += print_int(detail, ap);
	else if (type == 'u')
		len += print_uns(detail, ap);
	return (len);
}
