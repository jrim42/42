/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 00:27:55 by jrim              #+#    #+#             */
/*   Updated: 2021/11/16 18:20:01 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*tmp;

	new_lst = ft_lstnew(f(lst->content));
	tmp = lst;
	lst = lst->next;
	while (lst->next != NULL)
	{
		tmp->next = ft_lstnew((*f)(lst->content));
		if (!(tmp->next))
		{
			ft_lstclear(&new_lst, del);
			return (0);
		}
		lst = lst->next;
		tmp = tmp->next;
	}
	return (new_lst);
}
