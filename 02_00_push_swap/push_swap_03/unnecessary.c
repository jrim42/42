/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unnecessary.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:54:44 by jrim              #+#    #+#             */
/*   Updated: 2022/02/16 00:47:55 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd_display_one(int cmd);
void	stk_display_all(t_stk *stk_a, t_stk *stk_b);
void	data_swap(int *a, int *b);

void	cmd_display_one(int cmd)
{
	if (cmd / 10 == 0)
		write(1, "s", 1);
	else if (cmd / 10 == 1)
		write(1, "p", 1);
	else if (cmd / 10 == 2)
		write(1, "r", 1);
	else if (cmd / 10 == 3)
		write(1, "rr", 2);
	if (cmd % 10 == 0)
		write(1, "a\n", 2);
	else if (cmd % 10 == 1)
		write(1, "b\n", 2);
	else
	{
		if (cmd / 10 == 0)
			write(1, "s\n", 2);
		else
			write(1, "r\n", 2);
	}	
}

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

void	data_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
