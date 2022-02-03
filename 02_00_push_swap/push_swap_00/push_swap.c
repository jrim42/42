#include "push_swap.h"

void    push_swap(int argc, char **argv);
void    stk_fill(t_stack *stk, int argc, char **argv);
int     check_num(int argc, char **argv);
int     check_dup(int *input, int argc);
void    err_exit(void);

void    push_swap(int argc, char **argv)
{
    t_stack *stk_a;
    t_stack *stk_b;

    stk_init(&stk_a);
    stk_init(&stk_b);
    stk_fill(stk_a, argc, argv);
    stk_display_all(stk_a, stk_b);
    stk_quicksort(stk_a, stk_a->top, stk_a->top->prev, 0, stk_a->size - 1);
    stk_display_all(stk_a, stk_b);
}

void    stk_fill(t_stack *stk, int argc, char **argv)
{
    int    *input;
    int     idx;

    // input 예외 케이스 때문에 split 먼저
    if (check_num(argc, argv) == 0)
        err_exit();
    input = (int *)malloc((argc - 1) * sizeof(int));
    if (!input)
        return ;
    idx = 0;
    while (idx < argc - 1)
    {
        input[idx] = ft_atoi(argv[idx + 1]);
        idx++;
    }
    if (check_dup(input, argc) == 0)
        err_exit();
    idx = 0;
    while (idx < argc - 1)
    {
        stk_push(stk, nd_init(input[idx]));
        idx++;
    }
    free(input);
}

int     check_num(int argc, char **argv)
{
    int idx_1;
    int idx_2;

    // int 범위도 체크?
    idx_1 = 1;
    while (idx_1 < argc)
    {
        idx_2 = 0;
        if (argv[idx_1][idx_2] == '-' || argv[idx_1][idx_2] == '+')
            idx_2++;
        while(ft_isdigit(argv[idx_1][idx_2]))
            idx_2++;
        if (argv[idx_1][idx_2])
            return (0);
        idx_1++;
    }
    return (1);
}

int     check_dup(int *input, int argc)
{
    int idx_1;
    int idx_2;

    idx_1 = 0;
    while (idx_1 < argc)
    {
        idx_2 = idx_1 + 1;
        while (idx_2 < argc)
        {
            if (input[idx_1] == input[idx_2])
                return (0);
            idx_2++;
        }
        idx_1++;
    }
    return (1);
}

void    err_exit(void)
{
    //free?
    write(1, "Error\n", 6);
    exit(1);
}
