/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:38:54 by jrim              #+#    #+#             */
/*   Updated: 2022/02/18 12:54:08 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int argc, char **argv);
t_elm	*elm_init(t_elm *elm);
void	elm_free(t_elm *elm);

void	push_swap(int argc, char **argv)
{
	t_elm	*elm;

	if (argc < 3)
		return ;
	elm = elm_init(elm);
	stk_fill(elm->a, argc, argv);
	stk_a2b(elm, elm->piv, elm->a->size);
	printf("------ sort complete! -------\n");
	cmd_display_all(elm->cmdlst);
	cmd_cleaner(elm);
	cmd_display_all(elm->cmdlst);
	elm_free(elm);
}

t_elm	*elm_init(t_elm *elm)
{
	elm = (t_elm *)malloc(1 * sizeof(t_elm));
	if (!elm)
		exit(1);
	stk_init(&elm->a);
	stk_init(&elm->b);
	stk_init(&elm->cmdlst);
	elm->piv = (t_piv *)malloc(1 * sizeof(t_piv));
	if (!elm->piv)
		exit(1);
	return (elm);
}

void	elm_free(t_elm *elm)
{
	if (elm->a != NULL)
		stk_del(elm->a);
	if (elm->b != NULL)
		stk_del(elm->b);
	if (elm->cmdlst != NULL)
		stk_del(elm->cmdlst);
	if (elm->piv != NULL)
		free(elm->piv);
	free(elm);
}
