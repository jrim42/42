/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:09:15 by jrim              #+#    #+#             */
/*   Updated: 2021/12/19 23:47:02 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

# define TYPE "cspdiuxX%"
# define FLAG "# +-0"
# define DEC "0123456789"
# define HEX "0123456789abcdef"

typedef struct s_detail
{
	char	type;
	int		align;
	int		alt;
	int		pad;
	char	sign;
	int		wid;
	int		prec;
	int		base;
	int		str_len;
}			t_detail;

# define OFF 0
# define ON 1
# define LEFT -1
# define RIGHT 1

int		ft_printf(const char *form_str, ...);
void	init_detail(t_detail *detail);
int		parse_form(char *form, t_detail *detail, va_list ap);
int		check_type(char *form, t_detail *detail);

int		parse_flag(char *form, t_detail *detail, va_list ap);
int		parse_width(char *form, t_detail *detail, va_list ap);
int		parse_prec(char *form, t_detail *detail, va_list ap);
int		detect_type(t_detail *detail, va_list ap);

int		parse_int(t_detail *detail, va_list ap);
int		parse_hex(t_detail *detail, va_list ap);
int		print_num(t_detail *detail, char *str);
int		parse_numlen(t_detail *detail);

int		parse_str(t_detail *detail, va_list ap);
int		print_str(t_detail *detail, int ch, const char *str);
int		print_else(t_detail *detail);
int		parse_strlen(t_detail *detail);

void	fill_width(t_detail *detail, int cnt, int pad);
void	fill_prec(t_detail *detail, int cnt, int ret_len, int pad);
void	print_sign(t_detail *detail);
char	*ft_itoa_base(t_detail *detail, unsigned long num, char *base);
size_t	numlen_base(unsigned long num, size_t base_len);

#endif
