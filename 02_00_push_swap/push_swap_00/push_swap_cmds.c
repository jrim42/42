#include "push_swap.h"

void    commands(char *cmd);
void    push(char *cmd);
void    swap(char *cmd);
void    rotate(char *cmd);
void    rev_rotate(char *cmd);

void    commands(char *cmd)
{
    if (ft_strcmp(cmd, "pa") == 0 || ft_strcmp(cmd, "pb") == 0)
        push(cmd);
    else if (ft_strcmp(cmd, "sa") == 0 || ft_strcmp(cmd, "sb") == 0 || ft_strcmp(cmd, "ss") == 0)
        push(cmd);
    else if (ft_strcmp(cmd, "ra") == 0 || ft_strcmp(cmd, "rb") == 0 || ft_strcmp(cmd, "rr") == 0)
        push(cmd);
    else if (ft_strcmp(cmd, "rra") == 0 || ft_strcmp(cmd, "rrb") == 0 || ft_strcmp(cmd, "rrr") == 0)
        push(cmd);
}

void    push(char *cmd)
{

}

void    swap(char *cmd)
{

}

void    rotate(char *cmd)
{

}

void    rev_rotate(char *cmd)
{

}