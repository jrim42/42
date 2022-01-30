#include <stdio.h>
#include <stdlib.h>

typedef struct      s_node
{
    int             data;
    struct s_node   *prev;
    struct s_node   *next;
}                   t_node;

typedef struct  s_stack
{
    int         size;
    t_node      *top;
}               t_stack;

// stack init
void    stk_init(t_stack **stk)
{
    *stk = (t_stack *)malloc(sizeof(t_stack));
    (*stk)->top = NULL;
    (*stk)->size = 0;
}

// node init
t_node  *nd_init(int num)
{
    t_node *new_node;

    new_node = (t_node *)malloc(sizeof(t_node));
    new_node->data = num;
    // 순환구조
    new_node->next = new_node;
    new_node->prev = new_node;
    return (new_node);
}

// push
void    stk_push(t_stack *stk, t_node *new_top)
{
    t_node  *cur_top;

    if(stk->size == 0)
        stk->top = new_top;
    else
    {
        cur_top = stk->top;
        // 새로운 노드의 앞뒤 연결 
        new_top->prev = cur_top->prev;
        new_top->next = cur_top;
        // 기존 노드의 앞뒤 연결 해제
        cur_top->prev->next = new_top;
        cur_top->prev = new_top;
        stk->top = new_top; 
    }
    stk->size++;
}

// pop
t_node  *stk_pop(t_stack *stk)
{
    t_node  *cur_top;
    t_node  *new_top;

    cur_top = stk->top;
    if (stk->size == 1)
        stk->top = NULL;
    else
    {
        new_top = stk->top->next;
        new_top->prev = cur_top->prev;
        cur_top->prev->next = new_top;
        stk->top = new_top;  
        // 다른 노드와의 연결 끊기
        cur_top->prev = cur_top;
        cur_top->next = cur_top;
    }
    stk->size--; 
    return (cur_top);
}    

// swap
void    stk_swap(t_stack *stk)
{
    t_node  *cur_top;
    int     tmp;

    cur_top = stk->top;
    if (cur_top && cur_top->next)
    {
        tmp = cur_top->data;
        cur_top->data = cur_top->next->data;
        cur_top->next->data = tmp;
    }
}

// rotate
void    stk_rotate(t_stack *stk)
{
    t_node  *cur_top;

    cur_top = stk->top;
    stk->top = cur_top->next;
}

// reverse rotate
void    stk_rev_rotate(t_stack *stk)
{
    t_node  *cur_top;

    cur_top = stk->top;
    stk->top = cur_top->prev;
}

/*
void    stk_display(t_stack *stk_a, t_stack *stk_b)
{
    t_node  *tmp_a;
    t_node  *tmp_b;

    tmp_a = stk_a->top;
    tmp_b = stk_b->top;
    printf("--- ---\n");
    while (tmp_a || tmp_b)
    {
        if (tmp_a)
            printf(" %d  ", tmp_a->data);
        if (tmp_b)
            printf(" %d \n", tmp_b->data);

        tmp_a = tmp_a->next;
        tmp_b = tmp_b->next;
    }
    printf("--- ---\n");
    printf(" a   b \n");
}
*/

void    stk_display(t_stack *stk_a, t_stack *stk_b)
{
    t_node  *tmp_a;
    t_node  *tmp_b;
    int     size_a;
    int     size_b;

    tmp_a = stk_a->top;
    size_a = stk_a->size;
    tmp_b = stk_b->top;
    size_b = stk_b->size;
    printf(" a |");
    while (size_a--)
    {
        printf(" %d |", tmp_a->data);
        tmp_a = tmp_a->next;
    }
    printf("\n");
    printf(" b |");
    while (size_b--)
    {
        printf(" %d |", tmp_b->data);
        tmp_b = tmp_b->next;
    }
    printf("\n");
}

int main(void)
{
    t_stack *stk_a;
    t_stack *stk_b;

    stk_init(&stk_a);
    stk_init(&stk_b);
    stk_push(stk_a, nd_init(3));
    stk_push(stk_a, nd_init(4));
    stk_push(stk_a, nd_init(1));
    stk_push(stk_a, nd_init(2));
    stk_push(stk_b, stk_pop(stk_a));
    stk_push(stk_b, stk_pop(stk_a));
    stk_swap(stk_a);
    stk_swap(stk_b);
    stk_push(stk_a, stk_pop(stk_b));
    stk_display(stk_a, stk_b);
    stk_push(stk_a, stk_pop(stk_b));
    stk_display(stk_a, stk_b);
    stk_rotate(stk_a);
    stk_display(stk_a, stk_b);
    stk_rev_rotate(stk_a);
    stk_display(stk_a, stk_b);
    return (0);
}