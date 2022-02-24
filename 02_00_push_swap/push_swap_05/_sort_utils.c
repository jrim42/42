/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _sort_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 23:55:03 by jrim              #+#    #+#             */
/*   Updated: 2022/02/20 15:57:58 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sorted(t_stk *stk, int size);
int		is_rev_sorted(t_stk *stk, int size);
int		stk_min(t_stk *stk, int size);
int		stk_max(t_stk *stk, int size);

int	is_sorted(t_stk *stk, int size)
{
	int		min;
	t_node	*tmp;

	min = stk_min(stk, size);
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

int	is_rev_sorted(t_stk *stk, int size)
{
	int		min;
	t_node	*tmp;

	min = stk_min(stk, size);
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

int	stk_min(t_stk *stk, int size)
{
	int		min;
	t_node	*tmp;

	min = INT_MAX;
	tmp = stk->top;
	while (size--)
	{
		if (tmp->data <= min)
			min = tmp->data;
		tmp = tmp->next;
	}
	return (min);
}

int	stk_max(t_stk *stk, int size)
{
	int		max;
	t_node	*tmp;

	max = INT_MIN;
	tmp = stk->top;
	while (size--)
	{
		if (tmp->data >= max)
			max = tmp->data;
		tmp = tmp->next;
	}
	return (max);
}
