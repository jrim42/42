/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 20:46:41 by jrim              #+#    #+#             */
/*   Updated: 2022/08/10 00:31:40 by jrim             ###   ########.fr       */
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

# define NUM "0123456789"
# define WH_SP " \t\r\v\f\n"
# define INT_MAX 2147483647

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
	pthread_t		tid;
	int				eat_cnt;
	struct timeval	last_eat;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
	struct s_info	*info;
}					t_philo;

typedef struct s_param
{
	int		n_philo;
	int		ms_die;
	int		ms_eat;
	int		ms_sleep;
	int		n_eat;
}			t_param;

typedef struct s_info
{
	t_philo			*philos;
	t_param			param;
	int				is_done;
	struct timeval	birthday;
	pthread_mutex_t	*fork_mtx;
	pthread_mutex_t	msg_mtx;
}					t_info;

// _philo.c
int			init_info(t_param *param, t_info *info);
int			init_philo(t_philo *philo, t_param *param, t_info *info);
int			create_philo(t_info *info);
void		bye_philo(t_info *info);

// _param.c
int			init_param(int argc, char **argv, t_param *param);
int			_get_param(int argc, char **argv, t_param *param);
int			philo_atoi(const char *str);
char		*philo_strchr(const char *s, int c);

// _routine.c
void		*routine(void *philo_void);

// _eggshell.c
void		eggshell(t_info *info);

// _utils.c
long long	get_time_interval(struct timeval t1, struct timeval t2);
int			print_error(char *err_msg, int exit_state);
void		print_routine(t_philo *philo, char *msg);

#endif
