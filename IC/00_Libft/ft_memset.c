/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 21:12:52 by jrim              #+#    #+#             */
/*   Updated: 2021/11/14 21:13:16 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char			*ptr;
	unsigned int	idx;

	ptr = (char *)b;
	idx = 0;
	while (idx < len)
		ptr[idx++] = (unsigned char)c;
	return (b);
}
