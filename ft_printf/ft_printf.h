/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:09:15 by jrim              #+#    #+#             */
/*   Updated: 2021/11/25 16:09:21 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_F_H
# define FT_PRINT_F_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

# define TYPE "cspdiuxX%"

typedef struct s_detail
{
    char    type;
    int     sign;
    int     width;
    int     precision;
}	        t_detail;

int     ft_printf(const char *form_str, ...);
int	    detect_type(char *str, va_list arg_ptr);

int     print_char(const char **str, va_list arg_ptr);
int     print_str(const char **str, va_list arg_ptr);
int     print_per(const char **str);

int     print_hex(const char **str, va_list arg_ptr);
int     print_int(const char **str, va_list arg_ptr);
int     print_uns(const char **str, va_list arg_ptr);

#endif
