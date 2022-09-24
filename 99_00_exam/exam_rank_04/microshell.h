/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:02:54 by jrim              #+#    #+#             */
/*   Updated: 2022/09/24 15:24:47 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MICROSHELL_H
# define MICROSHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

//--------------- define and structs ----------------
# define STDIN		0
# define STDOUT		1
# define STDERR		2

# define TYPE_END	3
# define TYPE_PIPE	4
# define TYPE_BREAK	5

typedef struct s_info
{
    char 			**argv;
    int 			size;
	int 			type;
	int 			fd[2];
	struct s_info	*prev;
    struct s_info	*next;
} 					t_info;

//---------------------- parse ----------------------
int 	msh_parse(t_info **info, char **argv);
int 	cnt_argv_size(char **argv);
int 	check_end_type(char *argv);

//--------------------- execute ---------------------
void 	msh_exec(t_info *ptr, char **env);
void 	exec_cmd(t_info *tmp, char **env);

//---------------------- exit -----------------------
void	exit_fatal(void);
void	exit_execve(char *str);
int		exit_cd_1(void);
int		exit_cd_2(char *str);

//---------------------- utils ----------------------
int		ft_strlen(char *str);
char	*ft_strdup(char *str);
void 	ft_lstadd_back(t_info **info, t_info *new);
void 	free_all(t_info *info);

#endif