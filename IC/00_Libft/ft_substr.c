/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 21:30:27 by jrim              #+#    #+#             */
/*   Updated: 2021/11/14 21:31:53 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	sub_idx;
	char	*substr;

	s_len = ft_strlen(s);
	if (s_len == 0 || start > s_len || start < 0)
		return (0);
	sub_idx = 0;
	if (s_len - start >= len)
	{
		substr = (char *)malloc((len + 1) * sizeof(char));
		if (!(substr))
			return (0);
	}
	else
	{
		substr = (char *)malloc((s_len - start + 1) * sizeof(char));
		if (!(substr))
			return (0);
	}
	while (s[start] != '\0' && sub_idx < len)
		substr[sub_idx++] = s[start++];
	substr[sub_idx] = '\0';
	return (substr);
}
