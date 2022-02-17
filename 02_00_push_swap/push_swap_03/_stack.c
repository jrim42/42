/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _stack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 23:05:48 by jrim              #+#    #+#             */
/*   Updated: 2022/02/17 22:08:54 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stk_init(t_stk **stk);
t_node	*nd_init(int num);
void	stk_push(t_stk *stk, t_node *new_top);
t_node	*stk_pop(t_stk *stk);
void	nd_extract(t_stk *stk, t_node *nd, int cnt);
void	stk_del(t_node *start, int cnt);

void	stk_init(t_stk **stk)
{
	*stk = (t_stk *)malloc(sizeof(t_stk));
	(*stk)->top = NULL;
	(*stk)->size = 0;
}

t_node	*nd_init(int num)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->data = num;
	new_node->next = new_node;
	new_node->prev = new_node;
	return (new_node);
}

void	stk_push(t_stk *stk, t_node *new_top)
{
	t_node	*cur_top;

	if (stk->size == 0)
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
	if (stk->size == 1)
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

void	nd_extract(t_stk *stk, t_node *nd, int cnt)
{
	t_node	*prev_nd;
	t_node	*next_nd;

	//printf("in\n");
	if (nd == stk->top)
	{
		stk_pop(stk);
		return ;
	}
	prev_nd = nd->prev;
	next_nd = nd->next;
	// cmd_display_one(next_nd->data);
	// cmd_display_one(nd->data);
	// cmd_display_one(prev_nd->data);
	prev_nd->next = next_nd;
	next_nd->prev = prev_nd;
	nd->next = NULL;
	nd->prev = NULL;
	stk->size--;
	free(nd);
}

void	stk_del(t_node *start, int cnt)
{
	
}