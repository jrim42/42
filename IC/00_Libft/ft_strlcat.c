/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 21:21:01 by jrim              #+#    #+#             */
/*   Updated: 2021/11/14 21:21:22 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	unsigned int	dst_len;
	unsigned int	src_len;
	unsigned int	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	if (dst_len + 1 > dstsize)
		return (src_len + dstsize);
	while (src[i] != '\0' && dst_len + i + 1 < dstsize)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

int	main(void)
{
	char	dst_1[20] = "123";
	char	dst_2[5] = "pqr";

	printf("%zu\n", ft_strlcat(dst_1, "abc", 10));
	printf("%s\n", dst_1);
	printf("%lu\n", strlcat(dst_1, "abc", 10));
	printf("%s\n", dst_1);
	printf("%zu\n", ft_strlcat("ABCD", "abcd", 3));
	printf("%lu\n", strlcat("ABCD", "abcd", 3));
	printf("%zu\n", ft_strlcat(dst_2, "abcd", 3));
	printf("%s\n", dst_2);
	printf("%lu\n", strlcat(dst_2, "abcd", 3));
	printf("%s\n", dst_2);
	printf("%zu\n", ft_strlcat(dst_2, "abcdef", 5));
	printf("%s\n", dst_2);
	printf("%lu\n", strlcat(dst_2, "abcdef", 5));
	printf("%s\n", dst_2);
}
