/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:09:15 by jrim              #+#    #+#             */
/*   Updated: 2021/11/29 22:52:11 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_F_H
# define FT_PRINT_F_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

# define TYPE "cspdiuxX%"

typedef struct s_detail
{
    char    type;
    int     align;
    int     padding;
    int     width;
    int     prec;
    int     sp;
    int     base;
    int     sign;
}	        t_detail;

int     ft_printf(const char *form_str, ...);
int	    detect_type(t_detail *detail, va_list ap);

int     print_char(const char **str, va_list arg_ptr);
int     print_str(const char **str, va_list arg_ptr);
int     print_per(const char **str);

int     print_hex(const char **str, va_list arg_ptr);
int     print_int(const char **str, va_list arg_ptr);
int     print_uns(const char **str, va_list arg_ptr);

#endif
