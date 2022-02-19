/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimjeesoo <rimjeesoo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:38:54 by jrim              #+#    #+#             */
/*   Updated: 2022/02/19 14:53:56 by rimjeesoo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	elm_init(t_elm *elm);
void	elm_free(t_elm *elm);

int	main(int argc, char **argv)
{
	t_elm	*elm;

	if (argc < 3)
		return (0);
	elm = (t_elm *)malloc(1 * sizeof(t_elm));
	if (!elm)
		exit(1);
	elm_init(elm);
	stk_fill(elm->a, argc, argv);
	stk_a2b(elm, elm->piv, elm->a->size);
	printf("------ sort complete! -------\n");
	stk_display_all(elm->a, elm->b);
	cmd_cleaner(elm);
	cmd_display_all(elm->cmdlst);
	elm_free(elm);
	system("leaks a.out > leaks_result;\
			cat leaks_result | grep leaked && rm -rf leaks_result");
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
