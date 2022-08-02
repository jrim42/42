/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 20:46:41 by jrim              #+#    #+#             */
/*   Updated: 2022/08/02 17:33:41 by jrim             ###   ########.fr       */
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

typedef struct s_philo
{
	int				name;
	pthread_t		*thread;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
	pthread_mutex_t	*checker;
	struct timeval	last_eat;
	t_info			*info
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
	pthread_mutex_t	*is_done;
	int				flag;
	int				hungry_philo;
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
void	*eggshell_1(t_philo *philo);
void	*eggshell_2(t_info	*info);

// _print.c
long long	get_time_interval(struct timeval t1, struct timeval t2);
void		print_error(char *err_msg, int exit_state);
void		print_routine(t_philo *philo, char *msg);
void		print_param(t_param *param);

// _utils.c
int		ft_atoi(const char *str);
int		space_or_sign(const char *str, int *sign);
char	*ft_strchr(const char *s, int c);

#endif
