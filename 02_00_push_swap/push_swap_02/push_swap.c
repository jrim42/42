/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:38:54 by jrim              #+#    #+#             */
/*   Updated: 2022/02/15 20:43:19 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int argc, char **argv);

void	push_swap(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_pivot		*piv;

	stk_init(&a);
	stk_init(&b);
	stk_fill(a, argc, argv);
	piv = (t_pivot *)malloc(1 * sizeof(t_pivot));
	if (!piv)
		return ;
	stk_a2b(a, b, piv, a->size);
	stk_display_all(a, b);
	free(piv);
	//free?
}
