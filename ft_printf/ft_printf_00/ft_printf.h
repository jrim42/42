/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:09:15 by jrim              #+#    #+#             */
/*   Updated: 2021/12/08 22:30:49 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

# define TYPE "cspdiuxX%"
# define DEC "0123456789"
# define HEX "0123456789abcdef"

typedef struct s_detail
{
	char	type;
	int		alt;
	char	sign;
	int		base;
}			t_detail;

# define OFF 0
# define ON 1
# define LEFT 0
# define RIGHT 1

int		ft_printf(const char *form_str, ...);
void	init_detail(t_detail *detail);
int		detect_type(t_detail *detail, va_list ap);

int		parse_str(t_detail *detail, va_list ap);
int		print_str(t_detail *detail, int ch, const char *str);

int		parse_int(t_detail *detail, va_list ap);
int		parse_hex(t_detail *detail, va_list ap);
int		print_num(t_detail *detail, char *str);
char	*ft_itoa_base(t_detail *detail, unsigned long num, char *base);
int		numlen_base(unsigned long num, int base_len);

#endif
