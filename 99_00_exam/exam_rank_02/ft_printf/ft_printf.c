/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 21:09:43 by jrim              #+#    #+#             */
/*   Updated: 2022/08/16 13:16:24 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

// %s, %d, %x
// field width (no 0)
// precision (.)

typedef struct s_flag
{
	int		wid;
	int		dot;
	int		prc;
	char	type;
}	t_flag;

typedef struct s_arg
{
	char			*str;
	int				num;
	unsigned int	u_num;
	int				len;
	int				printed;
}	t_arg;

// ft_printf
int		ft_printf(const char *input, ...);
int		parse_input(va_list ap, char *input);
char	*find_type(char	*input);
int		print_with_flag(va_list ap, char *format, char *type);
void	init_struct(t_flag *flag, t_arg *arg);
void	parse_flag(t_flag *flag, char *format, char type);
void	print_str(t_flag *flag, t_arg *arg);
void	print_num(t_flag *flag, t_arg *arg);

// utils
int		ft_strlen(char *str);
int		ft_numlen_base(long long num, int base);
void	ft_putnstr(char *str, int len);
void	ft_putnchar(char ch, int len, int *printed);
void	ft_putnbr_base(long long num, int base);
char	*ft_strndup(char *str, int len);

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
	char	*type;
	char	*format;

	len = 0;
	while (*input)
	{
		if (*input == '%')
		{
			type = find_type(input + 1);
			if (type)
			{
				format = ft_strndup(input, (type + 1) - input);
				len += print_with_flag(ap, format, type);
				input += (type - input + 1);
			}
			else
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

char	*find_type(char	*input)
{
	int	i;

	i = 0;
	while (input[i] && \
		((input[i] >= '0' && input[i] <= '9') || input[i] == '.'))
		i++;
	if (input[i] == 's' || input[i] == 'd' || input[i] == 'x')
		return (input + i);
	else
		return (NULL);
}

int	print_with_flag(va_list ap, char *format, char *type)
{
	t_flag	flag;
	t_arg	arg;

	init_struct(&flag, &arg);
	parse_flag(&flag, format, *type);
	if (flag.type == 's')
	{
		arg.str = va_arg(ap, char *);
		print_str(&flag, &arg);
	}
	else if (*type == 'd')
	{
		arg.num = va_arg(ap, int);
		arg.len = ft_numlen_base(arg.num, 10);
		print_num(&flag, &arg);
	}
	else if (*type == 'x')
	{
		arg.u_num = va_arg(ap, unsigned int);
		arg.len = ft_numlen_base(arg.u_num, 16);
		print_num(&flag, &arg);
	}
	free(format);
	return (arg.printed);
}

void	init_struct(t_flag *flag, t_arg *arg)
{
	flag->wid = 0;
	flag->dot = 0;
	flag->prc = 0;
	flag->type = 0;
	arg->str = NULL;
	arg->num = 0;
	arg->u_num = 0;
	arg->len = 0;
	arg->printed = 0;
}

void	parse_flag(t_flag *flag, char *format, char type)
{
	int	i;

	flag->type = type;
	i = -1;
	while (format[++i])
	{
		if (format[i] >= '0' && format[i] <= '9' && !(flag->dot))
			flag->wid = (flag->wid * 10) + (format[i] - '0');
		else if (format[i] == '.')
			flag->dot = 1;
		else if (format[i] >= '0' && format[i] <= '9' && flag->dot)
			flag->prc = (flag->prc * 10) + (format[i] - '0');
	}
}

void	print_str(t_flag *flag, t_arg *arg)
{
	if (!arg->str)
		arg->str = "(null)";
	arg->len = ft_strlen(arg->str);
	if (flag->dot)
	{
		if (arg->len < flag->prc)
			flag->prc = arg->len;
	}
	else
		flag->prc = arg->len;
	ft_putnchar(' ', flag->wid - flag->prc, &(arg->printed));
	arg->printed += flag->prc;
	ft_putnstr(arg->str, flag->prc);
}

void	print_num(t_flag *flag, t_arg *arg)
{
	int	i;

	if (!arg->num && !arg->u_num && flag->dot && !flag->prc)
	{
		ft_putnchar(' ', flag->wid, &(arg->printed));
		return ;
	}
	if (flag->prc < arg->len)
		flag->prc = arg->len;
	if (arg->num < 0)
		flag->prc++;
	ft_putnchar(' ', flag->wid - flag->prc, &(arg->printed));
	if (arg->num < 0)
	{
		write(1, "-", 1);
		arg->len++;
	}
	i = -1;
	while (++i < flag->prc - arg->len)
		write(1, "0", 1);
	arg->printed += flag->prc;
	if (flag->type == 'd')
		ft_putnbr_base(arg->num, 10);
	else if (flag->type == 'd')
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
	while (num)
	{
		len++;
		num /= base;
	}
	return (len);
}

void	ft_putnstr(char *str, int len)
{
	int	i;

	i = 0;
	while (str[i] && i < len)
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_putnchar(char ch, int len, int *printed)
{
	int	i;

	i = -1;
	while (++i < len)
	{
		write(1, &ch, 1);
		(*printed)++;
	}
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

char	*ft_strndup(char *str, int len)
{
	char	*new_str;
	int		i;

	new_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (str[i] && i < len)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
