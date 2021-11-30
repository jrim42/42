/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:17:04 by jrim              #+#    #+#             */
/*   Updated: 2021/11/29 16:17:05 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_char(va_list arg_ptr);
int print_str(va_list arg_ptr);
int print_per(void);

int print_char(va_list arg_ptr)
{
	int		ch;

    ch = va_arg(arg_ptr, int);
    write(1, &ch, 1);
    return (1);
}

int print_str(va_list arg_ptr)
{
    return (0);
}

int print_per(void)
{
    write(1, "%", 1);
    return (1);
}
