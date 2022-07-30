/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 20:46:41 by jrim              #+#    #+#             */
/*   Updated: 2022/07/30 14:42:29 by jrim             ###   ########.fr       */
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
# define WH_SP " \t\r\v\f\n"

# define SUCCESS 1
# define FAILURE 0
# define VALID 1
# define INVALID 0

# define DFL 0
# define FORK 1
# define EAT 2
# define SLEEP 3
# define THINK 4
# define DIE -1

typedef struct s_philo
{
    pthread_t    thread;
    int          fork_l;
    int          fork_r;
    int          ms_start;
    int          ms_end;
    int          num_eat;
    int          num_sleep;
    int          num_think;
    int          state;
} t_philo;

typedef struct s_param
{
    int     number_of_philosophers;
    int     time_to_die;
    int     time_to_eat;
    int     time_to_sleep;
    int     number_of_times_each_philosopher_must_eat;
} t_param;

typedef struct s_state
{
    time_t  timestamp_in_ms;
    int     philo_num;
    int     philo_state;
} t_state;

//
void    malloc_err(void);
void	err_exit(char *err_msg, int exit_state);

// _param.c
int     parse_param(int argc, char **argv, t_param *param);
int     _check_arg(int argc, char **argv);

// _param_utils.c
int	    ft_atoi(const char *str);
int	    space_or_sign(const char *str, int *sign);
char	*ft_strchr(const char *s, int c);

// _state_utils.c
void    print_state(t_state *state);
void    print_param(t_param *param);

#endif