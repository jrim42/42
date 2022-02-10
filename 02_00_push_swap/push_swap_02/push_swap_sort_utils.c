/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 23:55:03 by jrim              #+#    #+#             */
/*   Updated: 2022/02/09 23:55:47 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack *stk);
int		stk_min(t_stack *stk);
int		stk_max(t_stack *stk);

void	sort_2(t_stack *stk)
{
	t_node	*nd_1;
	t_node	*nd_2;

	printf("------- sort_2 called! ------\n");
	nd_1 = stk->top;
	nd_2 = nd_1->next;
	if (nd_1->data > nd_2->data)
		cmd_swap("sa", stk, NULL);
}

int	stk_min(t_stack *stk)
{
	int		min;
	int		size;
	t_node	*tmp;

	min = 2147483647;
	size = stk->size;
	tmp = stk->top;
	while (size--)
	{
		if (tmp->data < min)
			min = tmp->data;
		tmp = tmp->next;
	}
	return (min);
}

int	stk_max(t_stack *stk)
{
	int		max;
	t_node	*tmp;

	max = -2147483648;
	tmp = stk->top;
	while (tmp)
	{
		if (tmp->data > max)
			max = tmp->data;
		tmp = tmp->next;
	}
	return (0);
}
