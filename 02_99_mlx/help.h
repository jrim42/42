/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:24:13 by jrim              #+#    #+#             */
/*   Updated: 2022/03/11 20:54:23 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELP_H
# define HELP_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

#define X_EVENT_KEY_PRESS 2     // mlx_hook 함수의 두 번째 인자인 
#define X_EVENT_KEY_RELEASE 3   // x_event에 들어가는 값

#define KEY_W 13    // W     
#define KEY_A 0     // A
#define KEY_S 1     // S
#define KEY_D 2     // D
#define KEY_ESC 53  // ESC

typedef	struct s_param // 키 값을 입력 받고 정해진 동작을 수행했는지
{                      // 여부를 판단하기 위해 선언하였다.
	int x;               // x값
	int y;               // y값
} t_param;

void    param_init(t_param *param); // 구조체 param 초기화 함수
int     key_press(int keycode, t_param *param); // 어떤 키가 눌렸는지 판단하고, 정의된 행동 수행

#endif