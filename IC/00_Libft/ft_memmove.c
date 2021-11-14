/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 21:09:55 by jrim              #+#    #+#             */
/*   Updated: 2021/11/14 21:11:37 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*dst_ptr;
	char			*src_ptr;
	unsigned int	idx;

	if (len == 0 || dst == src)
		return (dst);
	dst_ptr = (char *)dst;
	src_ptr = (char *)src;
	idx = 0;
	if (dst < src)
		while (idx < len)
		{
			dst_ptr[idx] = src_ptr[idx];
			idx++;
		}
	else
		while (idx < len)
		{
			dst_ptr[idx] = src_ptr[len - 1 - idx];
			idx++;
		}
	return (dst);
}
