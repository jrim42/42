/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimjeesoo <rimjeesoo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:38:54 by jrim              #+#    #+#             */
/*   Updated: 2022/02/10 15:54:24 by rimjeesoo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int argc, char **argv);
void	select_piv(t_stack *stk, int size, t_detail *detail);
int		is_sorted(t_stack *stk);
int		is_rev_sorted(t_stack *stk);

void	push_swap(int argc, char **argv)
{
	t_stack		*stk_a;
	t_stack		*stk_b;
	t_detail	*info;

	stk_init(&stk_a);
	stk_init(&stk_b);
	stk_fill(stk_a, argc, argv);
	stk_display_all(stk_a, stk_b);
	info = (t_detail *)malloc(1 * sizeof(t_detail));
	if (!info)
		return ;
	stk_a2b(stk_a, stk_b, info, stk_a->size);
	stk_display_all(stk_a, stk_b);
	free(info);
	//free?
}

void	select_piv(t_stack *stk, int size, t_detail *detail)
{
	int		s_idx;
	int		b_idx;
	int		*arr;

	printf("[select_piv called!]\n");
	s_idx = size / 3;
	b_idx = s_idx * 2;
	arr = (int *)malloc(size * sizeof(int));
	if (!arr)
		return ;
	arr_fill(stk, arr, size);
	arr_quicksort(arr, 0, size - 1);
	detail->s_piv = arr[s_idx];
	detail->b_piv = arr[b_idx];
	//free(arr);
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
