/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:16:49 by jrim              #+#    #+#             */
/*   Updated: 2021/11/30 22:17:30 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     print_int(va_list ap);
int     print_uns(va_list ap);
int     print_hex(char type, va_list ap);
char    *ft_itoa_base(long long num, char *base);
size_t  numlen_base(long long num, size_t base_len);

int print_int(va_list ap)
{
    long long   num;
    int         len;
    char        *str;

    num = va_arg(ap, int);
    if (num > INT_MAX || num < INT_MIN)
        return (0);
    str = ft_itoa(num);
    len = ft_strlen(str);
    write(1, str, len);
    free(str);
    return (len);
}

int print_uns(va_list ap)
{
    long long   num;
    int         len;
    char        *str;

    num = va_arg(ap, unsigned int);
    if (num > INT_MAX || num < INT_MIN)
        return (0);
    else if (num < 0)
        num = num + UINT_MAX + 1;
    str = ft_itoa(num);
    len = ft_strlen(str);
    write(1, str, len);
    free(str);
    return (len);
}

int print_hex(char type, va_list ap)
{
    long long   num;
    int         len;
    char        *str;

    if (type == 'p')
        num = (unsigned long)va_arg(ap, void *);
    else
        num = va_arg(ap, int);
    if (num > INT_MAX)
        return (0);
    else if (num < 0)
        num = num + UINT_MAX + 1;
    if (type == 'X')
        str = ft_itoa_base(num, HEX_U);
    else
        str = ft_itoa_base(num, HEX_L);
    len = ft_strlen(str);
    write(1, str, len);
    free(str);
    return (len);
}

char    *ft_itoa_base(long long num, char *base)
{
    size_t	base_len;
    size_t  idx;
    char    *str;

    base_len = ft_strlen(base);
    idx = numlen_base(num, base_len);
    str = (char *)malloc((idx + 1) * sizeof(char));
    if (!str)
        return (0);
    str[idx--] = '\0';
    while (num > 0)
    {
        str[idx--] = base[num % base_len];
        num /= base_len;
    }
    return (str);
}

size_t	numlen_base(long long num, size_t base_len)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		len++;
		num /= base_len;
	}
	return (len);
}