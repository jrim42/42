/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:18:26 by jrim              #+#    #+#             */
/*   Updated: 2021/12/21 22:15:20 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_flag(char **form, t_detail *detail, va_list ap);
void	parse_width(char **form, t_detail *detail, va_list ap);
void	parse_prec(char **form, t_detail *detail, va_list ap);
int		check_type(char *form, t_detail *detail, va_list ap);

void	parse_flag(char **form, t_detail *detail, va_list ap)
{
	while ((ft_strchr(FLAG, **form) || ft_isdigit(**form)) && **form)
	{
		if (**form == '#')
			detail->alt = 2;
		else if (**form == '+')
			detail->sign = '+';
		else if (**form == ' ' && detail->sign == OFF)
			detail->sign = ' ';
		else if (**form == '0')
			detail->pad = ON;
		else if (**form == '-')
			detail->align = LEFT;
		else if (**form == '*' || ft_isdigit(**form))
			parse_width(form, detail, ap);
		else if (**form == '.')
			parse_prec(form, detail, ap);
		(*form)++;
	}
}

void	parse_width(char **form, t_detail *detail, va_list ap)
{
	if (**form == '*')
	{
		detail->wid = va_arg(ap, int);
		if (detail->wid < 0)
			detail->align = LEFT;
		detail->wid *= (detail->wid > 0) - (detail->wid < 0);
		(*form)++;
	}
	else if (ft_isdigit(**form))
	{
		detail->wid = ft_atoi(*form);
		while (ft_isdigit(**form))
			(*form)++;
	}
	if (detail->align == OFF)
		detail->align = RIGHT;
	(*form)--;
}

void	parse_prec(char **form, t_detail *detail, va_list ap)
{
	(*form)++;
	if (**form == '*')
	{
		detail->prec = va_arg(ap, int);
		if (detail->prec < 0)
			detail->prec = -1;
		(*form)++;
	}
	else if (ft_isdigit(**form))
	{
		detail->prec = ft_atoi(*form);
		while (ft_isdigit(**form))
			(*form)++;
	}
	else if (ft_strchr(FLAG, **form) || ft_strchr(TYPE, **form))
		detail->prec = 0;
	(*form)--;
}

int	check_type(char *form, t_detail *detail, va_list ap)
{
	int		len;
	char	type;

	detail->type = *form;
	if (!ft_strchr(TYPE, detail->type) && detail->type)
		detail->str_len = 1;
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
