/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _state.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 17:21:27 by jrim              #+#    #+#             */
/*   Updated: 2022/07/30 14:38:27 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    print_state(t_state *state);
void    print_param(t_param *param);

void    print_state(t_state *state)
{
    int p_state;
    
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

void    print_param(t_param *param)
{
    printf("---------------------\n");
    printf("  philo  :  %d\n", param->number_of_philosophers);
    printf("   die   :  %d\n", param->time_to_die);
    printf("   eat   :  %d\n", param->time_to_eat);
    printf("  sleep  :  %d\n", param->time_to_sleep);
    if (param->number_of_times_each_philosopher_must_eat != -1)
        printf(" num eat :  %d\n", param->number_of_times_each_philosopher_must_eat);
    printf("---------------------\n");
}
