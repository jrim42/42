/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:38:54 by jrim              #+#    #+#             */
/*   Updated: 2022/02/07 00:56:03 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int argc, char **argv);
int		select_piv(t_stack *stk);
int		is_rev_sorted(t_stack *stk);
void	sort_3(t_stack *stk);

void	push_swap(int argc, char **argv)
{
	t_stack	*stk_a;
	t_stack	*stk_b;

	stk_init(&stk_a);
	stk_init(&stk_b);
	stk_fill(stk_a, argc, argv);
	stk_display_all(stk_a, stk_b);
	// size == 1 일때는 개행만 출력
	// if (stk_a->size == 3)
	//     printf("stk_sort_3\n");
	// else if (stk_a->size == 5)
	//     printf("stk_sort_5\n");
	// else
	//     stk_a2b(stk_a, stk_b, 6, 3);
	stk_a2b(stk_a, stk_b, stk_a->size);
	stk_display_all(stk_a, stk_b);
	//free?
}

int	select_piv(t_stack *stk)
{
	int piv_idx;

	piv_idx = (stk->size)/2;
	
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

void	sort_3(t_stack *stk)
{
	int		min;
	int		max;
	int		mid;

	min = stk_min(stk);
	max = stk_max(stk);
}