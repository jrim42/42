/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _utils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:59:40 by jrim              #+#    #+#             */
/*   Updated: 2022/07/04 18:01:47 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(char *str);
void	error_pid(pid_t pid);
void	pipe_error(int pip);
void	double_free(char **arr);

void	error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	error_pid(pid_t pid)
{
	if (pid < 0)
		error("pid is < 0");
}

void	pipe_error(int pip)
{
	if (pip < 0)
		perror("pipe() returns -1");
}

void	double_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i++])
		free(arr[i]);
}