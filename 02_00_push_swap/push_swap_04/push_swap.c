/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:38:54 by jrim              #+#    #+#             */
/*   Updated: 2022/02/21 20:39:28 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (elm->a->size > 1)
	{
		stk_a2b(elm, elm->piv, elm->a->size);
		if (elm->cmdlst->size > 0)
		{
			cmd_cleaner(elm);
			cmd_display_all(elm->cmdlst);
		}
	}
	//stk_display_all(elm->a, elm->b);
	elm_free(elm);
	//system("leaks push_swap > leaks_result;\
	//		cat leaks_result | grep leaked && rm -rf leaks_result");
	return (0);
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
