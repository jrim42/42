#include <stdio.h>
#include <stdlib.h>

typedef struct      s_node
{
    int             data;
    struct s_node   *prev;
    struct s_node   *next;
}                   t_node;