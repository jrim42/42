/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microsh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:02:50 by jrim              #+#    #+#             */
/*   Updated: 2022/10/28 12:33:44 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microsh.h"

int main(int argc, char **argv, char **env)
{
	t_info	*info;
	int 	i;

	if (argc == 1)
		return (0);
	info = NULL;
	i = 1;
	while (argv[i])
	{
		if (strcmp(argv[i], ";") != 0)
		{
			i += msh_parse(&info, &argv[i]);
			if (!argv[i])
				break;
		}
		i++;
	}
	if (info)
		msh_exec(info, env);
	free_all(info);
	return (0);
}

int	msh_err(int err_type, char *str)
{
	if (err_type == ERR_FATAL)
	{
		write(STDERR, "error: fatal\n", ft_strlen("error: fatal\n"));
		exit(EXIT_FAILURE);
	}
	else if (err_type == ERR_EXECVE)
	{
		write(STDERR, "error: cannot execute ", 
			ft_strlen("error: cannot execute "));
		write(STDERR, str, ft_strlen(str));
		write(STDERR, "\n", 1);
		exit(EXIT_FAILURE);
	} 
	else if (err_type == ERR_CD_1)
	{
		write(STDERR, "error: cd: bad arguments\n", 
			ft_strlen("error: cd: bad arguments\n"));
		return (EXIT_FAILURE);
	}
	else if (err_type == ERR_CD_2)
	{
		write(STDERR, "error: cd: cannot change directory to ", 
			ft_strlen("error: cd: cannot change directory to "));
		write(STDERR, str, ft_strlen(str));
		write(STDERR, "\n", 1);
		return (EXIT_FAILURE);
	}
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