/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 00:23:13 by jrim              #+#    #+#             */
/*   Updated: 2021/11/15 00:24:34 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!del || !(*lst))
		return ;
	tmp = (*lst);
	while (tmp)
	{
		tmp = (*lst);
		(*lst) = (*lst)->next;
		ft_lstdelone(*lst, del);
	}
	(*lst) = NULL;
}
