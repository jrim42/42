/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 21:26:06 by jrim              #+#    #+#             */
/*   Updated: 2021/11/14 21:26:42 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	idx;
	size_t	needle_len;
	char	*ptr;

	idx = 0;
	needle_len = ft_strlen(needle);
	ptr = (char *)haystack;
	if (!haystack && !needle)
		return (ptr);
	while (idx + needle_len <= len)
	{
		if (ft_strncmp(ptr, needle, needle_len) == 0)
			return (ptr);
		idx++;
		ptr++;
	}
	return (0);
}
