#include "ft_printf.h"

int	print_int(t_detail *detail, va_list ap)
{
	long long	num;
	char		*str;
	int			str_len;
	int			ret_len;

	num = va_arg(ap, int);
	if (num < 0)
		detail->sign = '-';
	num *= (num > 0) - (num < 0);
	str = ft_itoa_base(detail, num, DEC);
	str_len = ft_strlen(str);
	ret_len = parse_numlen(detail, &str_len);

    fill_str(detail, str_len, ret_len);
	print_sign(detail);
	fill_str(detail, ft_strlen(str), detail->prec);
	write(1, str, ft_strlen(str));
    fill_str(detail, str_len, ret_len);
	free(str);
	return (ret_len);
}

int	print_int(t_detail *detail, va_list ap)
{
	long long	num;
	char		*str;
	int			str_len;
	int			ret_len;

	num = va_arg(ap, int);
	if (num < 0)
		detail->sign = '-';
	num *= (num > 0) - (num < 0);
	str = ft_itoa_base(detail, num, DEC);
	str_len = ft_strlen(str);
	ret_len = parse_numlen(detail, &str_len);
	// if (detail->align == RIGHT)
	// 	printf("RIGHT\n");
	// else if (detail->align == LEFT)
	// 	printf("LEFT\n");
	if (detail->align != RIGHT)
	{
		print_sign(detail);
		write(1, str, ft_strlen(str));
	}
	if (detail->pad == ON)
		print_sign(detail);
	fill_str(detail, str_len, ret_len);
	if (detail->align == RIGHT)
		write(1, str, ft_strlen(str));
	free(str);
	return (ret_len);
}