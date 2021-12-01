/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:18:26 by jrim              #+#    #+#             */
/*   Updated: 2021/12/01 19:19:20 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_form(char *form, va_list ap);
int	parse_flag(char *form, t_detail *detail);
int	parse_wid(char *form, t_detail *detail);
int	parse_prec(char *form, t_detail *detail);
int	detect_type(t_detail *detail, va_list ap);

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

int	parse_flag(char *form, t_detail *detail)
{

}

int	parse_wid(char *form, t_detail *detail)
{

}

int	parse_prec(char *form, t_detail *detail)
{

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
