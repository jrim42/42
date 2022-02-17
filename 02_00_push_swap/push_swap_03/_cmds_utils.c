/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _cmds_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:51:58 by jrim              #+#    #+#             */
/*   Updated: 2022/02/17 22:55:24 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd_display_all(t_stk *cmdlst);
void	rrr_helper(t_elm *elm, int ra_cnt, int rb_cnt);
void	rr_cleaner(t_elm *elm, int new_cmd);
void	cmd_cleaner(t_elm *elm);

void	cmd_display_all(t_stk *cmdlst)
{
	t_node	*tmp;
	int		size;
	int		cmd_cnt;

	tmp = cmdlst->top->prev;
	size = cmdlst->size;
	cmd_cnt = 0;
	while (size--)
	{
		cmd_display_one(tmp->data);
		cmd_cnt++;
		tmp = tmp->prev;
	}
	printf("----- total : %d cmds -----\n", cmd_cnt);
}

void	rrr_helper(t_elm *elm, int ra_cnt, int rb_cnt)
{
	int		cnt;
	t_stk	*a;
	t_stk	*b;

	cnt = 0;
	a = elm->a;
	b = elm->b;
	while (cnt < ra_cnt && cnt < rb_cnt)
	{
		cmd_rev_rotate(32, elm);
		cnt++;
	}
	if (cnt < ra_cnt)
	{
		while (cnt++ < ra_cnt)
			cmd_rev_rotate(30, elm);
	}
	else if (cnt < rb_cnt)
	{
		while (cnt++ < rb_cnt)
			cmd_rev_rotate(31, elm);
	}
}

void	rr_cleaner(t_elm *elm, int new_cmd)
{
	t_stk	*cmdlst;
	int		cur_cmd;

	cmdlst = elm->cmdlst;
	cur_cmd = cmdlst->top->data;
	if (cur_cmd < 20)
		return ;
	if ((cur_cmd == 20 || cur_cmd == 21) && new_cmd == 32)
	{
		printf("1 in\n");
		stk_pop(cmdlst);
		if (cur_cmd == 20)
			stk_push(cmdlst, nd_init(31));
		else if (cur_cmd == 21)
			stk_push(cmdlst, nd_init(30));
	}
	else if (cur_cmd == 20 && new_cmd == 30)
	{
		printf("2 in\n");
		stk_pop(cmdlst);
	}
	else if (cur_cmd == 21 && new_cmd == 31)
	{
		printf("3 in\n");
		stk_pop(cmdlst);
	}
	else
	{
		printf("4 in\n");
		stk_push(elm->cmdlst, nd_init(new_cmd));
	}
}

// void	cmd_cleaner(t_elm *elm)
// {
// 	t_stk	*cmdlst;
// 	t_node	*tmp;
// 	int		size;

// 	cmdlst = elm->cmdlst;
// 	tmp = cmdlst->top->prev;
// 	size = cmdlst->size;
// 	while (size--)
// 	{
// 		if (tmp->data == 32)
// 		{
// 			if (tmp->next->data == 20 && tmp->next->next->data == 21)
// 			{
// 				tmp->data = -1;
// 				tmp->next->data = -1;
// 				tmp->next->next->data = -1;
// 			}
// 			else if (tmp->next->data == 20 && tmp->next->next->data == 21)
// 			{
// 				tmp->data = -1;
// 				tmp->next->data = -1;
// 				tmp->next->next->data = -1;
// 			}
// 			else if (tmp->next->data == 20)
// 			{
// 				tmp->data = 31;
// 				tmp->next->data = -1;
// 			}
// 			else if (tmp->next->data == 21)
// 			{
// 				tmp->data = 30;
// 				tmp->next->data = -1;
// 			}
// 		}
// 		else if (tmp->data == 31)
// 		{
// 			if (tmp->next->data == 21)
// 			{
// 				tmp->data = -1;
// 				tmp->next->data = -1;
// 			}
// 			else if (tmp->prev->data == 21)
// 			{
// 				tmp->data = -1;
// 				tmp->prev->data = -1;
// 			}
// 		}
// 		else if (tmp->data == 30)
// 		{
// 			if (tmp->next->data == 20)
// 			{
// 				tmp->data = -1;
// 				tmp->next->data = -1;
// 			}
// 			else if (tmp->prev->data == 20)
// 			{
// 				tmp->data = -1;
// 				tmp->prev->data = -1;
// 			}
// 		}
// 		tmp = tmp->prev;
// 	}
// }

void	cmd_cleaner(t_elm *elm)
{
	t_stk	*cmdlst;
	t_node	*tmp;
	int		size;

	cmdlst = elm->cmdlst;
	tmp = cmdlst->top->prev;
	size = cmdlst->size;
	while (size--)
	{	
		if (tmp->data == 32)
		{
			if (tmp->next->data == 20 && tmp->next->next->data == 21)
				nd_extract(cmdlst, tmp, 3);
			else if (tmp->next->data == 20 && tmp->next->next->data == 21)
				nd_extract(cmdlst, tmp, 3);
			else if (tmp->next->data == 20)
			{
				nd_extract(cmdlst, tmp->next, 1);
				tmp->data = 31;
			}
			else if (tmp->next->data == 21)
			{
				nd_extract(cmdlst, tmp->next, 1);
				tmp->data = 30;
			}
		}
		else if (tmp->data == 31)
		{
			if (tmp->next->data == 21)
				nd_extract(cmdlst, tmp, 2);
			else if (tmp->prev->data == 21)
				nd_extract(cmdlst, tmp, -2);
		}
		else if (tmp->data == 30)
		{
			if (tmp->next->data == 20)
				nd_extract(cmdlst, tmp, 2);
			else if (tmp->prev->data == 20)
				nd_extract(cmdlst, tmp, -2);
		}
		tmp = tmp->prev;
	}
}