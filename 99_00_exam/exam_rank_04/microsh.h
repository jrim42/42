/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microsh.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:02:54 by jrim              #+#    #+#             */
/*   Updated: 2022/09/24 17:18:28 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MICROSH_H
# define MICROSH_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

//--------------- define and structs ----------------
# define STDIN		0
# define STDOUT		1
# define STDERR		2

# define TYPE_END	0
# define TYPE_PIPE	1
# define TYPE_BREAK	2

# define ERR_FATAL	0
# define ERR_EXECVE 1
# define ERR_CD_1	2
# define ERR_CD_2	3

typedef struct s_info
{
    char 			**argv;
    int 			size;
	int 			type;
	int 			fd[2];
	struct s_info	*prev;
    struct s_info	*next;
} 					t_info;

//---------------------- main -----------------------
int		msh_err(int err_type, char *str);

//---------------------- parse ----------------------
int 	msh_parse(t_info **info, char **argv);
int 	cnt_argv_size(char **argv);
int 	check_end_type(char *argv);

//--------------------- execute ---------------------
void 	msh_exec(t_info *ptr, char **env);
void 	exec_cmd(t_info *tmp, char **env);
void 	exec_parent(t_info *tmp, pid_t pid, int *status, int pipe_open);
void 	exec_child(t_info *tmp, char **env);

//---------------------- utils ----------------------
int		ft_strlen(char *str);
char	*ft_strdup(char *str);
void 	ft_lstadd_back(t_info **info, t_info *new);
void 	free_all(t_info *info);

#endif