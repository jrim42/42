/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _parse.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:05:36 by jrim              #+#    #+#             */
/*   Updated: 2022/09/24 15:23:43 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

int msh_parse(t_info **info, char **argv)
{
    int 	size;
    t_info	*new;

	size = cnt_argv_size(argv);
	new  = (t_info *)malloc(sizeof(t_info));
    if (!(new))
        exit_fatal();
	new->argv = (char **)malloc(sizeof(char *) * (size + 1));
    if (!(new->argv))
        exit_fatal();
    new->size = size;
	new->next = NULL;
	new->prev = NULL;
    new->argv[size] = NULL;
    while (--size >= 0)
        new->argv[size] = ft_strdup(argv[size]);
    new->type = check_end_type(argv[new->size]);
    ft_lstadd_back(info, new);
    return (new->size);
}

int cnt_argv_size(char **argv)
{
    int i;
	
	i = 0;
    while (argv[i] && strcmp(argv[i], "|") != 0 && strcmp(argv[i], ";") != 0)
        i++;
    return (i);
}

int check_end_type(char *argv)
{
    if (!argv)
        return (TYPE_END);
    if (strcmp(argv, "|") == 0)
        return (TYPE_PIPE);
    if (strcmp(argv, ";") == 0)
        return (TYPE_BREAK);
    return (0);
}
