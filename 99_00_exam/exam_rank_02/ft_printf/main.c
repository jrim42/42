/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 21:12:43 by jrim              #+#    #+#             */
/*   Updated: 2022/08/05 23:09:31 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int	ft_printf(const char *input, ...);

int main(void)
{
	int	len;
	// ft_printf("%d\n", 123);
	len = ft_printf("%5s\n", "abc");
	ft_printf("len: %d\n", len);
	return (0);	
}