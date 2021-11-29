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

int print_char(const char **str, va_list arg_ptr);
int print_str(const char **str, va_list arg_ptr);
int print_per(const char **str);

int print_char(const char **str, va_list arg_ptr)
{
	int		num;

    num = va_arg(arg_ptr, int);
    write(1, &num, 1);
    (*str)++;
    return (1);
}

int print_str(const char **str, va_list arg_ptr)
{

}

int print_per(const char **str)
{
    write(1, "%", 1);
    return (1);
}
