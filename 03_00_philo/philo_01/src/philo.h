/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 20:46:41 by jrim              #+#    #+#             */
/*   Updated: 2022/08/04 13:37:17 by jrim             ###   ########.fr       */
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
# define DONE 1
# define UNDONE 0

# define RETURN_ERROR 1

typedef struct s_philo
{
	int				name;
	// int				state;
	int				eat_cnt;
	struct timeval	last_eat;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
	struct s_info	*info;
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
	t_philo			*philos;
	t_param			param;
	int				stuffed_philo;
	int				is_done;
	struct timeval	birthday;
	pthread_mutex_t	*fork_mtx;
	pthread_mutex_t	philo_mtx;
}					t_info;

// _philo.c
// main
int			init_info(t_param *param, t_info *info);
int			init_philo(t_philo *philo, t_param *param, t_info *info);
void		create_philo(t_info *info, t_philo *philo);
void		bye_philo(t_info *info);

// _param.c
int			init_param(int argc, char **argv, t_param *param);
int			_check_arg(int argc, char **argv);
void		_get_param(int argc, char **argv, t_param *param);
int			_check_param(int argc, t_param *param);

// _routine.c
void		*routine(void *philo_void);
// static void	philo_get_fork(t_philo *philo);
// static void	philo_eat(t_philo *philo);
// static void	philo_sleep(t_philo *philo);
// static void	philo_think(t_philo *philo);

// _eggshell.c
void		*eggshell(void	*void_info);

// _print.c
int			print_error(char *err_msg, int exit_state);
void		print_routine(t_philo *philo, char *msg);

void		print_param(t_param *param);
void		print_philo(t_philo *philo);

// _utils.c
long long	get_time_interval(struct timeval t1, struct timeval t2);
int			philo_atoi(const char *str);
char		*philo_strchr(const char *s, int c);

#endif
