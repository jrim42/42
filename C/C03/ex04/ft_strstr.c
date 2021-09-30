/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 10:35:07 by jrim              #+#    #+#             */
/*   Updated: 2021/09/22 19:56:50 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char	*s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i] != '\0')
	{
		if (s1[i] == '\0' | s1[i] < s2[i])
			return (-1);
		else if (s1[i] > s2[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = str;
	if (str[0] == '\0' && to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		if (ft_strcmp(ptr, to_find) == 0)
			return (ptr);
		i++;
		ptr++;
	}
	return (0);
}
