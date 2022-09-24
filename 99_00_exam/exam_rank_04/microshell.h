/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:02:54 by jrim              #+#    #+#             */
/*   Updated: 2022/09/24 14:59:55 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MICROSHELL_H
# define MICROSHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

# define STDIN		0
# define STDOUT		1
# define STDERR		2

# define TYPE_END	3
# define TYPE_PIPE	4
# define TYPE_BREAK	5

typedef struct s_base
{
    char 			**argv;
    int 			size;
	int 			type;
	int 			fd[2];
	struct s_base	*prev;
    struct s_base	*next;
} 					t_base;

#endif