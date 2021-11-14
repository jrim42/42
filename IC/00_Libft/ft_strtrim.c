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

int	trimmed_len(char *ptr, char const *set)
{
	int	idx;
	int	new_len;

	idx = 0;
	new_len = 0;
	while (ptr[idx] != '\0')
	{
		if (ft_strchr(set, ptr[idx]) == 0)
			new_len++;
		idx++;
	}
	return (new_len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	char	*new_str;
	int		idx;

	if (!s1 || !set)
		return ((char *)s1);
	ptr = (char *)s1;
	new_str = (char *)malloc((trimmed_len(ptr, set) + 1) * sizeof(char));
	if (!(new_str))
		return (0);
	idx = 0;
	while ((*ptr) != '\0')
	{
		if (ft_strchr(set, *ptr) == 0)
			new_str[idx++] = *ptr;
		ptr++;
	}
	new_str[idx] = '\0';
	return (new_str);
}

int	main(void)
{
	printf("%s\n", ft_strtrim("0abcde1", "0123"));
	printf("%s\n", ft_strtrim("0a1b2c3d4", "01234"));
	printf("%s\n", ft_strtrim("0abcde1", ""));
	printf("%s\n", ft_strtrim("", "0123"));
	printf("%s\n", ft_strtrim("", ""));
}
