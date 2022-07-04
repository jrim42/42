/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 19:18:28 by zkarapet          #+#    #+#             */
/*   Updated: 2022/07/04 18:05:30 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <sys/errno.h>

# include "../libft/libft.h"

// pipex.c
void	pipex(int inffd, int outffd, char **av, char **env);

// _parsing.c
char	*d_path(char **env_vars, char **cmd);
char	*parsing(char **env, char *cmd_arg);

// _child.c
void	child1(int fd1, int infile, char **av, char **env);
void	child2(int fd0, int outfile, char **av, char **env);

// _utils.c
void	error(char *str);
void	error_pid(pid_t pid);
void	pipe_error(int pip);
void	double_free(char **arr);

#endif
