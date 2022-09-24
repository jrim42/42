/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _utils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:05:21 by jrim              #+#    #+#             */
/*   Updated: 2022/09/24 17:20:44 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microsh.h"

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

void ft_lstadd_back(t_info **info, t_info *new)
{
    t_info *temp;

	if (!(*info))
		*info = new;
	else
	{
		temp = *info;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
		new->prev = temp;
	}
}

void free_all(t_info *info)
{
	t_info *temp;
	int i;

	while (info)
	{
		temp = info->next;
		i = 0;
		while (i < info->size)
			free(info->argv[i++]);
		free(info->argv);
		free(info);
		info = temp;
	}
	info = NULL;
}