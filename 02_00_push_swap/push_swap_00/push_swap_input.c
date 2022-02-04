#include "push_swap.h"

void    stk_fill(t_stack *stk, int argc, char **argv);
int     check_num(char **input);
int     check_dup(t_stack *stk);
void    err_exit(void);

void    stk_fill(t_stack *stk, int argc, char **argv)
{
    char    **input;
    int     idx_1;
    int     idx_2;
    int     data;

    idx_1 = 1;
    while (idx_1 < argc)
    {
        input = ft_split(argv[idx_1], ' ');
        if (check_num(input) == 0)
            err_exit();
        idx_2 = 0;
        while (input[idx_2])
        {
            data = ft_atoi(input[idx_2]);
            stk_push(stk, nd_init(data));
            idx_2++;
        }
        free(input);
        idx_1++;
    }
    if (check_dup(stk) == 0)
        err_exit();
}

int     check_num(char **input)
{
    int idx_1;
    int idx_2;

    // int 범위도 체크?
    idx_1 = 0;
    while (input[idx_1])
    {
        idx_2 = 0;
        if (input[idx_1][idx_2] == '-' || input[idx_1][idx_2] == '+')
            idx_2++;
        while(ft_isdigit(input[idx_1][idx_2]))
            idx_2++;
        if (input[idx_1][idx_2])
            return (0);
        idx_1++;
    }
    return (1);
}

int     check_dup(t_stack *stk)
{
    int     cnt_1;
    int     cnt_2;
    t_node  *tmp;
    t_node  *cur;

    cnt_1 = 0;
    tmp = stk->top;
    while (cnt_1 < stk->size)
    {
        cnt_2 = cnt_1 + 1;
        cur = tmp->next;
        while (cnt_2 < stk->size)
        {
            if (tmp->data == cur->data)
                return (0);
            cur = cur->next;
            cnt_2++;
        }
        tmp = tmp->next;
        cnt_1++;
    }
    return (1);
}

void    err_exit(void)
{
    //free?
    write(1, "Error\n", 6);
    exit(1);
}
