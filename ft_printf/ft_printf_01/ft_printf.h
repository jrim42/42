/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:09:15 by jrim              #+#    #+#             */
/*   Updated: 2021/12/01 19:20:46 by jrim             ###   ########.fr       */
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
# define FLAG "-0 *#+"
# define HEX_U "0123456789ABCDEF"
# define HEX_L "0123456789abcdef"

typedef struct s_detail
{
	char	type;
	int		adj;    // -
	int		pad;    // 0
	int		prec;   // .
	int		sp;     // space
	int		wid;    // width
	int		alt;    // #
	int		sign;   // sign
	int		base;   
}           t_detail;

# define OFF 0;
// # define IGNORED -1;

int		ft_printf(const char *form_str, ...);

int		parse_form(char *form, va_list ap);
// int		parse_flag(char *form, t_detail *detail);
int		parse_wid(char *form, t_detail *detail);
// int		parse_prec(char *form, t_detail *detail);
int		detect_type(t_detail *detail, va_list ap);

int		print_char(t_detail *detail, va_list ap);
int		print_str(t_detail *detail, va_list ap);
int		print_per(void);

int		print_int(va_list arg_ptr);
int		print_uns(va_list arg_ptr);
int		print_hex(t_detail *detail, va_list ap);
char	*ft_itoa_base(t_detail *detail, unsigned long num, char *base);
size_t	numlen_base(unsigned long num, size_t base_len);

void	init_detail(t_detail *detail);
// void	init_cs(t_detail *detail);
// void	init_diu(t_detail *detail);
// void	init_xXp(t_detail *detail);

#endif
