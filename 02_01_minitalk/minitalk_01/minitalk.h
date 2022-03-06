/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 21:15:15 by jrim              #+#    #+#             */
/*   Updated: 2022/03/06 12:40:40 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

// _client.c
void	send_msg(char *msg, int pid);
void	recieve_sig(int sig);
void	check_arg(int argc, char **argv, int *srv_pid);
void	print_dfl_msg_clt(int type, int num);

// _server.c
void	recieve_msg(int sig, siginfo_t *info, void *context);
void	print_ch(char ch, int *clt_pid);
void	print_dfl_msg_srv(int type, int num);

#endif
