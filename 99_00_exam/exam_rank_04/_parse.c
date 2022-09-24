/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _parse.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:05:36 by jrim              #+#    #+#             */
/*   Updated: 2022/09/24 14:59:06 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

void ft_lstadd_back(t_base **ptr, t_base *new)
{
    t_base *temp;

	if (!(*ptr))
		*ptr = new;
	else
	{
		temp = *ptr;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
		new->prev = temp;
	}
}

int size_argv(char **argv)
{
    int i = 0;
    while (argv[i] && strcmp(argv[i], "|") != 0 && strcmp(argv[i], ";") != 0)
        i++;
    return (i);
}

int check_end(char *av)
{
    if (!av)
        return (TYPE_END);
    if (strcmp(av, "|") == 0)
        return (TYPE_PIPE);
    if (strcmp(av, ";") == 0)
        return (TYPE_BREAK);
    return (0);
}

int parser_argv(t_base **ptr, char **av)
{
    int size = size_argv(av);
    t_base *new;

    if (!(new = (t_base *)malloc(sizeof(t_base))))
        exit_fatal();
    if (!(new->argv = (char **)malloc(sizeof(char *) * (size + 1))))
        exit_fatal();
    new->size = size;
	new->next = NULL;
	new->prev = NULL;
    new->argv[size] = NULL;
    while (--size >= 0)
        new->argv[size] = ft_strdup(av[size]);
    new->type = check_end(av[new->size]);
    ft_lstadd_back(ptr, new);
    return (new->size);
}