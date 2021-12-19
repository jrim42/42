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

int	parse_flag(char *form, t_detail *detail, va_list ap);
int	parse_prec(char *form, t_detail *detail, va_list ap);
int	parse_width(char *form, t_detail *detail, va_list ap);
int	detect_type(t_detail *detail, va_list ap);

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
		detail->align = LEFT;
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
			// *로 음수가 들어왔을 때 다시 확인하기
			detail->prec = -1;
			return (1);
		}
	}
	else
	{
		detail->prec = ft_atoi(form);
		if (detail->prec < 0)
			detail->align = LEFT;
			// 그리고?
		flag_len += numlen_base(detail->prec, 10);
	}
	if (detail->align != LEFT)
		detail->align = RIGHT;
	// if (detail->prec > 0)
	// 	detail->pad = ON;
	// padding이랑 precision에서 0이 출력되는 것을 나눠서 생각해야할 듯
	// num의 경우 prec가 원래 길이보다 크면 zero padding이 맞지만 char과 str은 그렇지 않다. 
	// 단 char과 str은 zero-padding 옵션이 별도로 있는 경우에는 0을 출력해주어야 한다.
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
	if (type == '%')
		len += print_per();
	else if (type == 'c')
		len += print_char(detail, ap);
	else if (type == 's')
		len += print_str(detail, ap);
	else if (type == 'd' || type == 'i' || type == 'u')
		len += parse_int(detail, ap);
	else if (type == 'x' || type == 'X' || type == 'p')
		len += parse_hex(detail, ap);
	return (len);
}
