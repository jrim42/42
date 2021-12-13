/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:09:15 by jrim              #+#    #+#             */
/*   Updated: 2021/12/12 16:35:04 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

# define TYPE "cspdiuxX%"
# define DEC "0123456789"
# define HEX "0123456789abcdef"

typedef struct s_detail
{
	char	type;
	int		align;
	int		pad;
	int		prec;
	int		wid;
	int		alt;
	char	sp;
	char	sign;
	int		base;
}			t_detail;

# define OFF 0
# define ON 1
# define LEFT -1
# define RIGHT 1

int		ft_printf(const char *form_str, ...);
void	init_detail(t_detail *detail);

int		parse_form(char *form, t_detail *detail, va_list ap);
int		parse_flag(char *form, t_detail *detail, va_list ap);
int		parse_width(char *form, t_detail *detail, va_list ap);
int		parse_prec(char *form, t_detail *detail);
int		detect_type(t_detail *detail, va_list ap);

int		print_char(t_detail *detail, va_list ap);
int		print_str(t_detail *detail, va_list ap);
int		print_per(void);

int		print_int(t_detail *detail, va_list arg_ptr);
int		print_uns(t_detail *detail, va_list arg_ptr);
int		print_hex(t_detail *detail, va_list ap);
char	*ft_itoa_base(t_detail *detail, unsigned long num, char *base);
size_t	numlen_base(unsigned long num, size_t base_len);

void	print_width(t_detail *detail, int str_len, int ret_len);
void	print_alt(t_detail *detail);
void	print_sign(t_detail *detail);
int		parse_numlen(t_detail *detail, int *str_len);
int		parse_strlen(t_detail *detail, int *str_len);

#endif