/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 21:09:43 by jrim              #+#    #+#             */
/*   Updated: 2022/08/16 13:53:05 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

// %s, %d, %x
// field width (no 0)
// precision (.)

typedef struct s_arg
{
	char			type;
	char			*str;
	int				num;
	unsigned int	u_num;
	int				len;
	int				printed;
}	t_arg;

// ft_printf
int		ft_printf(const char *input, ...);
int		parse_input(va_list ap, char *input);
int		print_arg(va_list ap, char type);
void	init_struct(t_arg *arg);
void	print_num(t_arg *arg);

// utils
int		ft_strlen(char *str);
int		ft_numlen_base(long long num, int base);
void	ft_putnbr_base(long long num, int base);

//------------------------ ft_printf ------------------------//

int	ft_printf(const char *input, ...)
{
	va_list		ap;
	int			ret;

	if (!input)
		return (-1);
	va_start(ap, input);
	ret = parse_input(ap, (char *)input);
	va_end(ap);
	return (ret);
}

int	parse_input(va_list ap, char *input)
{
	int		len;
	char	type;
	char	*format;

	len = 0;
	while (*input)
	{
		if (*input == '%')
		{
			type = *(input + 1);
			if (type == 's' || type == 'd' || type == 'x')
			{
				len += print_arg(ap, type);
				input++;
			}
			input++;
		}
		else
		{
			len++;
			write(1, input++, 1);
		}
	}
	return (len);
}

int	print_arg(va_list ap, char type)
{
	t_arg	arg;

	init_struct(&arg);
	arg.type = type;
	if (type == 's')
	{
		arg.str = va_arg(ap, char *);
		if (!arg.str)
		arg.str = "(null)";
		arg.len = ft_strlen(arg.str);
		write(1, arg.str, arg.len);
	}
	else if (type == 'd')
	{
		arg.num = va_arg(ap, int);
		arg.len = ft_numlen_base(arg.num, 10);
		print_num(&arg);
	}
	else if (type == 'x')
	{
		arg.u_num = va_arg(ap, unsigned int);
		arg.len = ft_numlen_base(arg.u_num, 16);
		print_num(&arg);
	}
	return (arg.printed);
}

void	init_struct(t_arg *arg)
{
	arg->str = NULL;
	arg->num = 0;
	arg->u_num = 0;
	arg->len = 0;
	arg->printed = 0;
	arg->type = 0;
}

void	print_num(t_arg *arg)
{
	int	i;

	if (arg->num < 0)
	{
		write(1, "-", 1);
		arg->len++;
	}
	if (arg->type == 'd')
		ft_putnbr_base(arg->num, 10);
	else if (arg->type == 'x')
		ft_putnbr_base(arg->u_num, 16);
}

//------------------------ utils ------------------------//

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_numlen_base(long long num, int base)
{
	int	len;

	len = 0;
	if (num < 0)
	{
		len++;
		num *= -1;
	}
	while (num)
	{
		len++;
		num /= base;
	}
	return (len);
}

void	ft_putnbr_base(long long num, int base)
{
	char	*dec = "0123456789";
	char	*hex = "0123456789abcdef";

	if (num < 0)
		num = -num;
	if (num >= base)
	{
		ft_putnbr_base(num / base, base);
		ft_putnbr_base(num % base, base);
	}
	else
	{
		if (base == 10)
			write(1, &dec[num], 1);
		else if (base == 16)
			write(1, &hex[num], 1);
	}
}
