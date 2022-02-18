/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:37:22 by jrim              #+#    #+#             */
/*   Updated: 2022/02/18 13:01:06 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	push_swap(argc, argv);
	system("leaks a.out > leaks_result;\
			cat leaks_result | grep leaked && rm -rf leaks_result");
	return (0);
}
