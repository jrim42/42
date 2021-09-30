/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 13:09:27 by jrim              #+#    #+#             */
/*   Updated: 2021/09/29 18:26:54 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	i;

	size = max - min;
	i = 0;
	if (max - min <= 0)
		return (0);
	*range = (int *)malloc(size * sizeof(int));
	if (!(*range))
		return (-1);
	while (i < size)
	{
		(*range)[i] = min++;
		i++;
	}
	return (size);
}
