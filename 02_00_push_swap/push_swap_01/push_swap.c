/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:38:54 by jrim              #+#    #+#             */
/*   Updated: 2022/02/07 01:39:21 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int argc, char **argv);
int		select_piv(t_stack *stk);
void	sort_2(t_stack *stk);

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

int	select_piv(t_stack *stk)
{
	int		piv_idx;
	int		*arr;
	int		piv;

	piv_idx = (stk->size)/2;
	arr = (int *)malloc(stk->size * sizeof(int));
	if (!arr)
		return (0);
	arr_fill(stk, arr);
	arr_quicksort(arr, 0, stk->size - 1);
	piv = arr[piv_idx];
	free(arr);
	return (piv);
}

void	sort_2(t_stack *stk)
{
	printf("2 in\n");
	t_node	*nd_1;
	t_node	*nd_2;
	
	nd_1 = stk->top;
	nd_2 = nd_1->next;
	if (nd_1->data > nd_2->data)
		cmd_swap("sa", stk);
}