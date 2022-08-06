/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 12:22:24 by jrim              #+#    #+#             */
/*   Updated: 2022/08/06 12:47:22 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define BUF_SIZE 1

# define ERROR -1
# define ONE_LINE 1
# define LAST_LINE 0

int	get_next_line(char **line);

#endif