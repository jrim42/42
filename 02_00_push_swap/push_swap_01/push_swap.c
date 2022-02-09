/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:38:54 by jrim              #+#    #+#             */
/*   Updated: 2022/02/09 23:14:43 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int argc, char **argv);
int	select_piv(t_stack *stk, int size);
void	sort_2(t_stack *stk);
int		is_rev_sorted(t_stack *stk);
int		is_sorted(t_stack *stk);

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

void	sort_2(t_stack *stk)
{
	printf("[sort_2 called!]\n");
	t_node	*nd_1;
	t_node	*nd_2;
	
	nd_1 = stk->top;
	nd_2 = nd_1->next;
	if (nd_1->data > nd_2->data)
		cmd_swap("sa", stk);
}

int		is_rev_sorted(t_stack *stk)
{
	int		min;
	int		size;
	t_node	*tmp;

	//printf("-------sort check-------\n");
	min = stk_min(stk);
	//printf("[min : %d]\n", min);
	size = stk->size;
	tmp = stk->top->prev;
	if (tmp->data != min)
		return (0);
	//printf("[tmp : %d]\n", tmp->data);
	while (size--)
	{
		if (tmp->data >= min)
			min = tmp->data;
		else
			return (0);
		tmp = tmp->prev;
	}
	//printf("-----check end here-----\n");
	return (1);
}

int		is_sorted(t_stack *stk)
{
	int		min;
	int		size;
	t_node	*tmp;

	//printf("-------sort check-------\n");
	min = stk_min(stk);
	//printf("[min : %d]\n", min);
	size = stk->size;
	tmp = stk->top;
	if (tmp->data != min)
		return (0);
	//printf("[tmp : %d]\n", tmp->data);
	while (size--)
	{
		if (tmp->data >= min)
			min = tmp->data;
		else
			return (0);
		tmp = tmp->next;
	}
	//printf("-----check end here-----\n");
	return (1);
}