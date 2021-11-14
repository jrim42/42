/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 20:53:56 by jrim              #+#    #+#             */
/*   Updated: 2021/11/14 20:54:08 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char			*ptr;
	unsigned int	idx;

	ptr = (char *)malloc(count * size);
	if (!ptr)
		return (0);
	idx = 0;
	while (idx < count)
		ptr[idx++] = 0;
	return (ptr);
}

/*
void    *ft_calloc(size_t count, size_t size)
{
    char    *ptr;

    ptr = (char *)malloc(count * size);
    if (!ptr)
        return (0);
    ft_memset(ptr, 0, count * size);
    return (ptr);
}
*/
