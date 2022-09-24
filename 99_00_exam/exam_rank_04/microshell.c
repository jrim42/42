/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:02:50 by jrim              #+#    #+#             */
/*   Updated: 2022/09/24 15:00:29 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

int main(int ac, char **av, char **env)
{
	t_base *ptr = NULL;
	int i;

	i = 1;
	if (ac > 1)
	{
		while (av[i])
    	{
            if (strcmp(av[i], ";") == 0)
            {
                i++;
                continue ;
            }
    	    i += parser_argv(&ptr, &av[i]);
    	    if (!av[i])
    	        break;
    	    else
    	        i++;
    	}
	/*while (ptr)
	{
		
		printf("=================\n");
		for (i = 0; i < ptr->size; i++)
			printf("%s\n", ptr->argv[i]);
		printf("TYPE: %d\n", ptr->type);
		printf("SIZE: %d\n", ptr->size);
		printf("=================\n");
		ptr = ptr->next;
	}
	(void)**env;
	printf("END\n");*/
		if (ptr)
			exec_cmds(ptr, env);
		free_all(ptr);
	}
	return (0);
}