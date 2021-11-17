/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 21:28:19 by jrim              #+#    #+#             */
/*   Updated: 2021/11/14 21:30:04 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	trimmed_len(char **ptr, char const *set)
{
	int	start;
	int	end;
	int	ptr_idx;

	ptr_idx = 0;
	while (ft_strchr(set, (*ptr)[ptr_idx]) != 0)
		ptr_idx++;
	start = ptr_idx;
	ptr_idx = ft_strlen(*ptr) - 1;
	while (ft_strchr(set, (*ptr)[ptr_idx]) != 0)
		ptr_idx--;
	end = ptr_idx;
	(*ptr) += start;
	return (end - start + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	char	*new_str;
	int		new_len;
	int		idx;

	ptr = (char *)s1;
	new_len = trimmed_len(&ptr, set);
	new_str = (char *)malloc((new_len + 1) * sizeof(char));
	if (!(new_str))
		return (0);
	idx = 0;
	while (new_len--)
	{
		new_str[idx] = *ptr;
		idx++;
		ptr++;
	}
	new_str[idx] = '\0';
	return (new_str);
}
