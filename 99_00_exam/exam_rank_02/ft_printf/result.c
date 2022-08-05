/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 21:12:43 by jrim              #+#    #+#             */
/*   Updated: 2022/08/06 00:26:08 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

int	ft_printf(char const *format, ...);

int	main(void)
{
	int	len;

	len = printf("|10.0s |%10.0s|\n", "Hello");
	printf("len: %d\n", len);
	len = printf("|10.s  |%10.s|\n", "Hello");
	printf("len: %d\n", len);
	len = printf("|10s   |%10s|\n", "Hello");
	printf("len: %d\n", len);
	len = printf("|10.4s |%10.4s|\n", "HEllo");
	printf("len: %d\n", len);
	len = printf("|10.7s |%10.7s|\n", "HEllo");
	printf("len: %d\n", len);
	len = printf("|.7s   |%.7s|\n", "HEllo");
	printf("len: %d\n", len);
	len = printf("|.3s   |%.3s|\n", "HEllo");
	printf("len: %d\n", len);

	printf("-----------------------------------\n");

	len = printf("|d    |%d|\n", 1234);
	printf("len: %d\n", len);
	len = printf("|3d   |%3d|\n", 1234);
	printf("len: %d\n", len);
	len = printf("|7d   |%7d|\n", 1234);
	printf("len: %d\n", len);
	len = printf("|.d   |%.d|\n", 1234);
	printf("len: %d\n", len);
	len = printf("|.3d  |%.3d|\n", 1234);
	printf("len: %d\n", len);
	len = printf("|.6d  |%.6d|\n", 1234);
	printf("len: %d\n", len);
	len = printf("|.6d  |%.6d|\n", -1234);
	printf("len: %d\n", len);
	len = printf("|3.3d |%3.3d|\n", 1234);
	printf("len: %d\n", len);
	len = printf("|3.3d |%3.3d|\n", -1234);
	printf("len: %d\n", len);
	len = printf("|6.3d |%6.3d|\n", 1234);
	printf("len: %d\n", len);
	len = printf("|6.3d |%6.3d|\n", -1234);
	printf("len: %d\n", len);
	len = printf("|3.7d |%3.7d|\n", 1234);
	printf("len: %d\n", len);
	len = printf("|3.7d |%3.7d|\n", -1234);
	printf("len: %d\n", len);
	len = printf("|9.7d |%9.7d|\n", 1234);
	printf("len: %d\n", len);
	len = printf("|9.7d |%9.7d|\n", -1234);
	printf("len: %d\n", len);
}