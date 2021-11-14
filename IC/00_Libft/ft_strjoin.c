/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 21:20:33 by jrim              #+#    #+#             */
/*   Updated: 2021/11/14 21:20:46 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, char *src);

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		idx;
	int		total_len;
	char	*new_str;

	idx = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	total_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	new_str = (char *)malloc(total_len * sizeof(char));
	new_str[0] = '\0';
	ft_strcat(new_str, (char *)s1);
	ft_strcat(new_str, (char *)s2);
	return (new_str);
}

char	*ft_strcat(char *dst, char *src)
{
	int	dst_idx;
	int	src_idx;

	dst_idx = 0;
	src_idx = 0;
	while (dst[dst_idx] != '\0')
		dst_idx++;
	while (src[src_idx] != '\0')
		dst[dst_idx++] = src[src_idx++];
	dst[dst_idx] = '\0';
	return (dst);
}

int	main(void)
{
	printf("%p : %s\n", ft_strjoin("", ""), ft_strjoin("", ""));
	printf("%p : %s\n", ft_strjoin("", "def"), ft_strjoin("", "def"));
	printf("%p : %s\n", ft_strjoin("abc", ""), ft_strjoin("abc", ""));
	printf("%p : %s\n", ft_strjoin("abc", "def"), ft_strjoin("abc", "def"));
}
