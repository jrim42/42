#include <stdio.h>
#include "libft/libft.h"

typedef struct t_stack
{
    t_list *top;
    int     size;
} t_stack;

void    st_new(t_stack **stack);
void    st_push(t_stack *stack, t_list *node);
t_list* st_pop(t_stack *stack);

int main(void)
{
    
}

void    st_new(t_stack **stack)
{
    (*stack) = (t_stack *)malloc(sizeof(t_stack));
    (*stack)->top = NULL;
    (*stack)->size = 0;
}

void    st_push(t_stack *stack, t_list *node)
{
    //empty stack
    if (stack->size == 0)
        stack->top = node;
    //unempty stack
    else
    {
        node->next = stack->top;
        stack->top = node;
    }
    
}

t_list*  st_pop(t_stack *stack)
{
    t_list *tmp;

    if (stack->size != 0)
    {
        tmp = stack->top;
        stack->top = stack->top->next;
        stack->size--;
    }
    return (tmp);
}
