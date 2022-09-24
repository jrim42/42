/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:02:50 by jrim              #+#    #+#             */
/*   Updated: 2022/09/24 15:22:48 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

int main(int argc, char **argv, char **env)
{
	t_info *info;
	int i;

	if (argc == 1)
		return (0);
	info = NULL;
	i = 1;
	while (argv[i])
	{
		if (strcmp(argv[i], ";") != 0)
		{
			i += msh_parse(&info, &argv[i]);
			if (argv[i])
				break;
		}
		i++;
	}
	if (info)
		msh_exec(info, env);
	free_all(info);
	return (0);
}

/*while (info)
{
	
	printf("=================\n");
	for (i = 0; i < info->size; i++)
		printf("%s\n", info->argv[i]);
	printf("TYPE: %d\n", info->type);
	printf("SIZE: %d\n", info->size);
	printf("=================\n");
	info = info->next;
}
(void)**env;
printf("END\n");*/