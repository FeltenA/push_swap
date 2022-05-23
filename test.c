#include <stdio.h>
#include "push_swap.h"

void    print_stack(t_stack *a)
{
    printf("\ntest:\n");
    while (a)
    {
        printf("%d\n", a->num);
        a = a->next;
    }
}