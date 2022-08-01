/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 20:46:41 by jrim              #+#    #+#             */
/*   Updated: 2022/08/01 18:36:46 by jrim             ###   ########.fr       */
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
	int				name;
	pthread_t		*thread;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
	pthread_mutex_t	*checker;
	struct timeval	last_eat;
	
	// int				ms_start;
	// int				ms_end;
	// int				num_eat;
	// int				num_sleep;
	// int				num_think;
}					t_philo;

typedef struct s_param
{
	int		num_philo;
	int		ms_to_die;
	int		ms_to_eat;
	int		ms_to_sleep;
	int		num_eat;
}			t_param;

typedef struct s_info
{
	t_philo			*philo;
	t_param			*param;
	pthread_mutex_t	*fork;
	struct timeval	birthday;
}					t_info;

// _param.c
int		parse_param(int argc, char **argv, t_param *param);
int		_check_arg(int argc, char **argv);

// _routine.c
void	*routine(t_philo *philo);
void	philo_get_fork(t_philo *philo);
void	philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);

// _eggshell.c
void	*eggshell(t_philo *philo);

// _print.c
void	print_error(char *err_msg, int exit_state);
void	print_state(t_state *state);
void	print_param(t_param *param);

// _utils.c
int		ft_atoi(const char *str);
int		space_or_sign(const char *str, int *sign);
char	*ft_strchr(const char *s, int c);

#endif
