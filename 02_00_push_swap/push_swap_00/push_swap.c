/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:38:54 by jrim              #+#    #+#             */
/*   Updated: 2022/02/05 21:39:19 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int argc, char **argv);
void	select_piv(t_stack *stk);

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
	stk_a2b(stk_a, stk_b, 6, 3);
	stk_display_all(stk_a, stk_b);
	//free?
}

void	select_piv(t_stack *stk)
{
}
