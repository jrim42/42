/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimjeesoo <rimjeesoo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:38:54 by jrim              #+#    #+#             */
/*   Updated: 2022/02/10 23:35:13 by rimjeesoo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int argc, char **argv);

void	push_swap(int argc, char **argv)
{
	t_stack		*stk_a;
	t_stack		*stk_b;
	t_pivot 	*piv;

	stk_init(&stk_a);
	stk_init(&stk_b);
	stk_fill(stk_a, argc, argv);
	stk_display_all(stk_a, stk_b);
	piv = (t_pivot *)malloc(1 * sizeof(t_pivot));
	if (!piv)
		return ;
	stk_a2b(stk_a, stk_b, piv, stk_a->size);
	stk_display_all(stk_a, stk_b);
	free(piv);
	//free?
}
