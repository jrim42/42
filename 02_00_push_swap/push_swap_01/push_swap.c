/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:38:54 by jrim              #+#    #+#             */
/*   Updated: 2022/02/09 23:25:15 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int argc, char **argv);
int		select_piv(t_stack *stk, int size);
int		is_sorted(t_stack *stk);
int		is_rev_sorted(t_stack *stk);


void	push_swap(int argc, char **argv)
{
	t_stack	*stk_a;
	t_stack	*stk_b;

	stk_init(&stk_a);
	stk_init(&stk_b);
	stk_fill(stk_a, argc, argv);
	
	stk_display_all(stk_a, stk_b);
	stk_a2b(stk_a, stk_b, stk_a->size);
	stk_display_all(stk_a, stk_b);
	//free?
}

int	select_piv(t_stack *stk, int size)
{
	int		piv_idx;
	int		*arr;
	int		piv;

	piv_idx = size/2 - 1;
	arr = (int *)malloc(size * sizeof(int));
	if (!arr)
		return (0);
	arr_fill(stk, arr, size);
	arr_quicksort(arr, 0, size - 1);
	piv = arr[piv_idx];
	// for (int i = 0; i < stk->size; i++)
	// 	printf("%d ", arr[i]);
	free(arr);
	return (piv);
}

int		is_sorted(t_stack *stk)
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

int		is_rev_sorted(t_stack *stk)
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