/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 20:46:41 by jrim              #+#    #+#             */
/*   Updated: 2022/05/18 17:26:33 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

# define NUM "0123456789"

# define DFL 0
# define FORK 1
# define EAT 2
# define SLEEP 3
# define THINK 4
# define DIE -1

typedef struct s_param
{
    int number_of_philosophers;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int number_of_times_each_philosopher_must_eat;
} t_param;

typedef struct s_state
{
    time_t  timestamp_in_ms;
    int     philo_num;
    int     philo_state;
} t_state;

// _param.c
int     parse_param(int argc, char **argv, t_param *param);
int     _check_arg(int argc, char **argv);
void    _get_param(int argc, char **argv, t_param *param);

// _param_utils.c
int	    ft_atoi(const char *str);
int	    space_or_sign(const char *str, int *sign);
char	*ft_strchr(const char *s, int c);

// _state_utils.c
void    print_state(t_state *state);

#endif