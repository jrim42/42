/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _print.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 17:21:27 by jrim              #+#    #+#             */
/*   Updated: 2022/07/31 22:11:27 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_error(char *err_msg, int exit_state);
void	print_state(t_state *state);
void	print_param(t_param *param);

void	print_error(char *err_msg, int exit_state)
{
	printf("error: %s\n", err_msg);
	// exit 사용 불가함수라서 수정해야함
	exit (exit_state);
}

void	print_state(t_state *state)
{
	int	p_state;

	p_state = state->philo_state;
	printf("%ld %d", state->timestamp_in_ms, state->philo_num);
	if (p_state == FORK)
		printf(" has taken a fork\n");
	else if (p_state == EAT)
		printf(" is eating\n");
	else if (p_state == SLEEP)
		printf(" is sleeping\n");
	else if (p_state == THINK)
		printf(" is thinking\n");
	else if (p_state == -1)
		printf(" died\n");
}

void	print_param(t_param *param)
{
	printf("---------------------\n");
	printf("  philo  :  %d\n", param->num_philo);
	printf("   die   :  %d\n", param->ms_to_die);
	printf("   eat   :  %d\n", param->ms_to_eat);
	printf("  sleep  :  %d\n", param->ms_to_sleep);
	if (param->num_eat != -1)
		printf(" num eat :  %d\n", param->num_eat);
	printf("---------------------\n");
}
