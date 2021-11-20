/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:15:35 by jrim              #+#    #+#             */
/*   Updated: 2021/11/20 18:34:55 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

# ifndef MAX
#  define MAX 10000
# endif

char    *get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
//char    *ft_strcat(char const *s1, char const *s2);
//char    *ft_strdup(char const *s1);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

#endif