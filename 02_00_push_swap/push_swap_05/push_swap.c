/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:38:54 by jrim              #+#    #+#             */
/*   Updated: 2022/02/24 11:59:33 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_filter(t_elm *elm, t_stk *a);
void	elm_init(t_elm *elm);
void	elm_free(t_elm *elm);

int	main(int argc, char **argv)
{
	t_elm	*elm;

	if (argc < 2)
		return (0);
	elm = (t_elm *)malloc(1 * sizeof(t_elm));
	if (!elm)
		return (0);
	elm_init(elm);
	stk_fill(elm, argc, argv);
	sort_filter(elm, elm->a);
	if (elm->cmdlst->size > 4)
		cmd_cleaner(elm);
	cmd_display_all(elm->cmdlst);
	elm_free(elm);
	return (0);
}

void	sort_filter(t_elm *elm, t_stk *a)
{
	int	size;

	size = a->size;
	if (size < 2)
		return ;
	else if (size == 2)
		sort_2(elm, a);
	else if (size == 3)
		sort_3_only(elm, a);
	else if (size == 4)
		sort_4(elm, a);
	else if (size == 5)
		sort_5(elm, a);
	else
		stk_a2b(elm, elm->piv, elm->a->size);
}

void	elm_init(t_elm *elm)
{
	stk_init(&elm->a);
	stk_init(&elm->b);
	stk_init(&elm->cmdlst);
	elm->piv = (t_piv *)malloc(1 * sizeof(t_piv));
	if (!elm->piv)
		exit(1);
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
