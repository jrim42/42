/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:38:54 by jrim              #+#    #+#             */
/*   Updated: 2022/02/15 23:06:36 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int argc, char **argv);
void	elm_init(t_elm *elm);

void	push_swap(int argc, char **argv)
{
	t_elm	*elm;

	elm = (t_elm *)malloc(1 * sizeof(t_elm));
	if (!elm)
	{
		printf("elm allocation failed\n");
		exit(1);
	}
	elm_init(elm);
	stk_fill(elm->a, argc, argv);
	stk_a2b(elm, elm->piv, elm->a->size);
	stk_display_all(elm->a, elm->b);
	cmd_display(elm->cmdlst);
	//free?
}

void	elm_init(t_elm *elm)
{
	stk_init(&elm->a);
	stk_init(&elm->b);
	elm->piv = (t_piv *)malloc(1 * sizeof(t_piv));
	if (!elm->piv)
	{
		printf("piv allocation failed\n");
		exit(1);
	}
}
