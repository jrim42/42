/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:24:13 by jrim              #+#    #+#             */
/*   Updated: 2022/03/11 14:25:32 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELP_H
# define HELP_H

# include <stdlib.h>

#define X_EVENT_KEY_PRESS 2     // mlx_hook 함수의 두 번째 인자인 
#define X_EVENT_KEY_RELEASE 3   // x_event에 들어가는 값

#define KEY_W 13    // MacOS의 키보드 코드들이다.          
#define KEY_A 0     //
#define KEY_S 1     // 위에서 부터 차례대로
#define KEY_D 2     //
#define KEY_ESC 53  // 'W' 'A' 'S' 'D' 'ESC'들의 키보드 코드이다.

typedef	struct s_param // 키 값을 입력 받고 정해진 동작을 수행했는지
{                      // 여부를 판단하기 위해 선언하였다.
	int x;               // x값
	int y;               // y값
} t_param;

#endif