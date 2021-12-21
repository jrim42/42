/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:18:26 by jrim              #+#    #+#             */
/*   Updated: 2021/12/21 14:47:03 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_flag(char *form, t_detail *detail, va_list ap);
int	parse_width(char *form, t_detail *detail, va_list ap);
int	parse_prec(char *form, t_detail *detail, va_list ap);
int	detect_type(t_detail *detail, va_list ap);

int	parse_flag(char *form, t_detail *detail, va_list ap)
{
	int	form_idx;

	form_idx = 1;
	if (*form == '#')
		detail->alt = 2;
	else if (*form == '+')
		detail->sign = '+';
	else if (*form == ' ' && detail->sign == OFF)
		detail->sign = ' ';
	else if (*form == '0')
		detail->pad = ON;
	else if (*form == '-')
		detail->align = LEFT;
	else if (*form == '.')
		form_idx += parse_prec(++form, detail, ap);
	else if (*form == '*' || ft_isdigit(*form))
		form_idx += parse_width(form, detail, ap) - 1;
	return (form_idx);
}

int	parse_width(char *form, t_detail *detail, va_list ap)
{
	int	flag_len;

	flag_len = 0;
	if (*form == '*')
	{
		detail->wid = va_arg(ap, int);
		if (detail->wid < 0)
		{
			detail->align = LEFT;
			detail->wid *= -1;
		}
		flag_len++;
	}
	else if (ft_isdigit(*form))
	{
		detail->wid = ft_atoi(form);
		flag_len += numlen_base(detail->wid, 10);
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
			detail->prec = -1;
		flag_len++;
	}
	else if (ft_isdigit(*form))
	{
		detail->prec = ft_atoi(form);
		while (*(form + flag_len) == '0')
			flag_len++;
		flag_len += numlen_base(detail->prec, 10);
	}
	else if (ft_strchr(FLAG, *form) || ft_strchr(TYPE, *form))
		detail->prec = 0;
	return (flag_len);
}

int	detect_type(t_detail *detail, va_list ap)
{
	int		len;
	char	type;

	if (detail->align == LEFT)
		detail->pad = OFF;
	len = 0;
	type = detail->type;
	if (ft_strchr("%cs", type))
		len += parse_str(detail, ap);
	else if (ft_strchr("diu", type))
		len += parse_int(detail, ap);
	else if (ft_strchr("xXp", type))
		len += parse_hex(detail, ap);
	else
	{
		print_str(detail, detail->type, 0);
		len += detail->ret_len;
	}
	return (len);
}
