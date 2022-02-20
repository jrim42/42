/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _stack_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:42:42 by jrim              #+#    #+#             */
/*   Updated: 2022/02/20 15:43:25 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stk_append(t_stk *stk, t_node *new_nd);
void	stk_push(t_stk *stk, t_node *new_top);
t_node	*stk_pop(t_stk *stk);

void	stk_append(t_stk *stk, t_node *new_nd)
{
	t_node	*cur_top;

	if (new_nd == NULL)
		return ;
	else if (stk->size == 0)
		stk->top = new_nd;
	else
	{
		cur_top = stk->top;
		new_nd->prev = cur_top->prev;
		new_nd->next = cur_top;
		cur_top->prev->next = new_nd;
		cur_top->prev = new_nd;
	}
	stk->size++;
}

void	stk_push(t_stk *stk, t_node *new_top)
{
	t_node	*cur_top;

	if (new_top == NULL)
		return ;
	else if (stk->size == 0)
		stk->top = new_top;
	else
	{
		cur_top = stk->top;
		new_top->prev = cur_top->prev;
		new_top->next = cur_top;
		cur_top->prev->next = new_top;
		cur_top->prev = new_top;
		stk->top = new_top;
	}
	stk->size++;
}

t_node	*stk_pop(t_stk *stk)
{
	t_node	*cur_top;
	t_node	*new_top;

	cur_top = stk->top;
	if (stk->size == 0)
		return (NULL);
	else if (stk->size == 1)
		stk->top = NULL;
	else
	{
		new_top = stk->top->next;
		new_top->prev = cur_top->prev;
		cur_top->prev->next = new_top;
		stk->top = new_top;
		cur_top->prev = cur_top;
		cur_top->next = cur_top;
	}
	stk->size--;
	return (cur_top);
}
