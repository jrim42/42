/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:08:41 by jrim              #+#    #+#             */
/*   Updated: 2021/12/11 00:35:13 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *form, ...);
void	init_detail(t_detail *detail);

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
	detail->sp = OFF;
	detail->sign = OFF;
	detail->base = 10;
}
