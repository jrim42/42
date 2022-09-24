/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _utils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:05:21 by jrim              #+#    #+#             */
/*   Updated: 2022/09/24 15:00:22 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

int	ft_strlen(char *str)
{
	int len;
	
	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *str)
{
	int		size;
	char	*new;

	if (!str)
		return (NULL);
	size = ft_strlen(str);
	new = (char *)malloc(sizeof(char) * (size + 1));
	if (!new)
		return (NULL);
	new[size] = '\0';
	while (--size >= 0)
		new[size] = str[size];
	return (new);
}

void free_all(t_base *ptr)
{
	t_base *temp;
	int i;

	while (ptr)
	{
		temp = ptr->next;
		i = 0;
		while (i < ptr->size)
			free(ptr->argv[i++]);
		free(ptr->argv);
		free(ptr);
		ptr = temp;
	}
	ptr = NULL;
}