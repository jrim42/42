/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unnecessary.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:54:44 by jrim              #+#    #+#             */
/*   Updated: 2022/02/19 15:13:12 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stk_display_all(t_stk *stk_a, t_stk *stk_b);

void	stk_display_all(t_stk *stk_a, t_stk *stk_b)
{
	t_node	*tmp_a;
	t_node	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = stk_a->top;
	size_a = stk_a->size;
	tmp_b = stk_b->top;
	size_b = stk_b->size;
	printf("%s a |", YELLOW);
	while (size_a--)
	{
		printf(" %d |", tmp_a->data);
		tmp_a = tmp_a->next;
	}
	printf("\n");
	printf(" b |");
	while (size_b--)
	{
		printf(" %d |", tmp_b->data);
		tmp_b = tmp_b->next;
	}
	printf("%s\n", RESET);
}