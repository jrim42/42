/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _state_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 17:21:27 by jrim              #+#    #+#             */
/*   Updated: 2022/05/18 17:25:57 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    print_state(t_state *state)
{
    int p_state;
    
    p_state = state->philo_state;
    printf("%d %d", state->timestamp_in_ms, state->philo_num);
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