/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 18:47:19 by heha              #+#    #+#             */
/*   Updated: 2022/09/17 18:48:09 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, int count, size_t size)
{
	void	*new;

	new = (void *)malloc(size * count);
	if (!new)
		return (NULL);
	if (ptr && count > 0)
		ft_memcpy(new, ptr, size * (count - 1));
	free(ptr);
	return (new);
}
