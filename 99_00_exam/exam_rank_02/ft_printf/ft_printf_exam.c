/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_exam.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 21:09:43 by jrim              #+#    #+#             */
/*   Updated: 2022/08/05 23:08:58 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

// %s, %d, %x
// field width (no 0)
// precision (.)

// ft_printf
int		ft_printf(const char *input, ...);
int		parse_input(va_list ap, char *input);
char	*find_type(char	*input);
int	print_with_flag(va_list ap, char *format, char *type);

// utils
int		ft_strlen(char *str);
int		ft_numlen(int num);
int		ft_hexlen(unsigned int hex);
void	ft_putnstr(char *str, int len);
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

// 서식자 위치
char	*find_type(char	*input)
{
	int	i;

	i = 0;
	while (input[i] && ((input[i] >= '0' && input[i] <= '9') || input[i] == '.'))
		i++;
	if (input[i] == 's' || input[i] == 'd' || input[i] == 'x')
		return (input + i);
	else
		return (NULL);
}

int	print_with_flag(va_list ap, char *format, char *type)
{
	int		width;
	int		dot;
	int		prec;
	int		i;

	width = 0;
	dot = 0;
	prec = 0;
	i = -1;
	while (format[++i])
	{
		if (format[i] >= '0' && format[i] <= '9' && !dot)
			width = (width * 10) + (format[i] - '0');
		else if (format[i] == '.')
			dot = 1;
		else if (format[i] >= '0' && format[i] <= '9' && dot)
			prec = (prec * 10) + (format[i] - '0');
	}
	free(format);

	char			*str;
	int				num;
	unsigned int	u_num;
	int				len;
	int				printed_len;

	num = 0;
	u_num = 0;
	len = 0;
	printed_len = 0;
	if (*type == 's')
	{
		str = va_arg(ap, char *);
		if (!str)
			str = "(null)";
		len = ft_strlen(str);
		if (dot)
		{
			if (len < prec)
				prec = len;
		}
		else
			prec = len;
		i = -1;
		while (++i < width - prec)
		{
			write(1, " ", 1);
			printed_len++;
		}
		printed_len += prec;
		ft_putnstr(str, prec);
	}
	else if (*type == 'd' || *type == 'x')
	{
		if (*type == 'd')
		{
			num = va_arg(ap, int);
			len = ft_numlen(num);
		}
		else if (*type == 'x')
		{
			u_num = va_arg(ap, unsigned int);
			len = ft_hexlen(u_num);
		}
		if (!num && !u_num && dot && !prec)
		{
			i = -1;
			while (++i < width)
			{
				write(1, " ", 1);
				printed_len++;
			}
			return (printed_len);
		}
		if (prec < len)
			prec = len;
		if (num < 0)
			prec++;
		i = -1;
		while (++i < width - prec)
		{
			write(1, " ", 1);
			printed_len++;
		}
		if (num < 0)
		{
			write(1, "-", 1);
			len++;
		}
		i = -1;
		while (++i < prec - len)
			write(1, "0", 1);
		printed_len += prec;
		if (*type == 'd')
			ft_putnbr_base(num, 10);
		else if (*type == 'd')
			ft_putnbr_base(u_num, 16);
	}
	return (printed_len);
}

//------------------------ utils ------------------------//

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int		ft_numlen(int num)
{
	int len;

	len = 0;
	while (num)
	{
		len++;
		num /= 10;
	}
	return (len);
}

int		ft_hexlen(unsigned int hex)
{
	int len;

	len = 0;
	while (hex)
	{
		len++;
		hex /= 16;
	}
	return (len);
}

void	ft_putnstr(char *str, int len)
{
	int i;

	i = 0;
	while (str[i] && i < len)
	{
		write(1, &str[i], 1);
		i++;
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