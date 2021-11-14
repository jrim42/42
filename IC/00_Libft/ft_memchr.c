/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 21:07:04 by jrim              #+#    #+#             */
/*   Updated: 2021/11/14 21:08:03 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	idx;
	unsigned char	*ptr;

	idx = 0;
	ptr = (unsigned char *)s;
	while (idx < n)
	{
		if (ptr[idx] == (unsigned char)c)
			return (&s[idx]);
		idx++;
	}
	return (0);
}
