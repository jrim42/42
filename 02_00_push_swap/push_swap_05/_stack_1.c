/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _stack_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 23:05:48 by jrim              #+#    #+#             */
/*   Updated: 2022/02/20 15:49:16 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stk_init(t_stk **stk);
t_node	*nd_init(int num);
void	stk_del(t_stk *stk);

void	stk_init(t_stk **stk)
{
	*stk = (t_stk *)malloc(sizeof(t_stk));
	if (!stk)
		exit(1);
	(*stk)->top = NULL;
	(*stk)->size = 0;
}

t_node	*nd_init(int num)
{
	t_node	*new_nd;

	new_nd = (t_node *)malloc(sizeof(t_node));
	if (!new_nd)
		exit(1);
	new_nd->data = num;
	new_nd->next = new_nd;
	new_nd->prev = new_nd;
	return (new_nd);
}

void	stk_del(t_stk *stk)
{
	t_node	*tmp;
	int		size;

	tmp = stk->top;
	size = stk->size;
	while (size--)
	{
		tmp = stk_pop(stk);
		tmp->prev = 0;
		tmp->next = 0;
		free(tmp);
	}
	stk->top = 0;
	free(stk);
}
