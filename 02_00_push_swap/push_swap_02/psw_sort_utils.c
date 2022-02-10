/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimjeesoo <rimjeesoo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 23:55:03 by jrim              #+#    #+#             */
/*   Updated: 2022/02/10 23:34:09 by rimjeesoo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_detail(t_pivot *piv, int *cnt_1, int *cnt_2, int *cnt_3);
int		is_sorted(t_stack *stk);
int		is_rev_sorted(t_stack *stk);
int		stk_min(t_stack *stk);
int		stk_max(t_stack *stk);

void	init_detail(t_pivot *piv, int *cnt_1, int *cnt_2, int *cnt_3)
{
	piv->b_piv = 0;
	piv->s_piv = 0;
	*cnt_1 = 0;
	*cnt_2 = 0;
	*cnt_3 = 0;
}

int	is_sorted(t_stack *stk)
{
	int		min;
	int		size;
	t_node	*tmp;

	min = stk_min(stk);
	size = stk->size;
	tmp = stk->top;
	if (tmp->data != min)
		return (0);
	while (size--)
	{
		if (tmp->data >= min)
			min = tmp->data;
		else
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	is_rev_sorted(t_stack *stk)
{
	int		min;
	int		size;
	t_node	*tmp;

	min = stk_min(stk);
	size = stk->size;
	tmp = stk->top->prev;
	if (tmp->data != min)
		return (0);
	while (size--)
	{
		if (tmp->data >= min)
			min = tmp->data;
		else
			return (0);
		tmp = tmp->prev;
	}
	return (1);
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
