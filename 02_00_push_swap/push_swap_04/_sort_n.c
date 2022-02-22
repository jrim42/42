/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _sort_n.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:49:59 by jrim              #+#    #+#             */
/*   Updated: 2022/02/22 23:10:26 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_elm *elm, t_stk *stk);
void	sort_3_only(t_elm *elm, t_stk *stk);
void	sort_3_part(t_elm *elm, t_stk *stk);
void	sort_5(t_elm *elm, t_stk *stk);

void	sort_2(t_elm *elm, t_stk *stk)
{
	t_node	*nd_1;
	t_node	*nd_2;

	nd_1 = stk->top;
	nd_2 = nd_1->next;
	if (nd_1->data > nd_2->data)
		cmd_swap(0, elm, NULL);
}

void	sort_3_only(t_elm *elm, t_stk *stk)
{
	t_node	*nd;
	int		min;
	int		max;

	if (is_sorted(stk, 3) == 1) // 123
		return ;
	nd = stk->top->next;
	min = stk_min(stk, 3);
	max = stk_max(stk, 3);
	if (nd->data == max)
	{
		cmd_rev_rotate(30, elm); // 231
		if (nd->prev->data == min) // 132
			cmd_swap(0, elm, 0);
	}
	else if (nd->prev->data == max)
	{
		cmd_rotate(20, elm, 0); // 312
		if (nd->next->data == min) // 321
			cmd_swap(0, elm, 0);
	}
	else if (nd->next->data == max) // 213
		cmd_swap(0, elm, 0);
}

void	sort_3_part(t_elm *elm, t_stk *stk)
{
	t_node	*nd;
	int		min;
	int		max;

	if (is_sorted(stk, 3) == 1)
		return ;
	nd = stk->top->next;
	min = stk_min(stk, 3);
	max = stk_max(stk, 3);
	if (nd->data == min && nd->next->data == max)
		cmd_swap(0, elm, 0);
	else if (nd->prev->data == max)
		cmd_swap(0, elm, 0);
	if (nd->data == max)
	{
		cmd_rotate(20, elm, 0);
		cmd_swap(0, elm, 0);
		cmd_rev_rotate(30, elm);
		nd = stk->top->next;
		if (nd->data == min && nd->next->data == max)
			cmd_swap(0, elm, 0);
	}
}

void	sort_5(t_elm *elm, t_stk *stk)
{
	printf("[sort_5 called]");
	if (elm || stk)
		return ;
}
