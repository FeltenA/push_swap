#include "push_swap.h"

void    swap_stack(t_stack **begin)
{
    t_stack *save;

    if (!begin || !(*begin)->next)
        return ;
    save = (*begin)->next->next;
    (*begin)->next->next = *begin;
    *begin = (*begin)->next;
    (*begin)->next->next = save;
}

void    push_stack(t_stack **a, t_stack **b)
{
    t_stack *save;

    if (!b || !a || !(*b))
        return ;
    save = (*b)->next;
    if (*a)
        (*b)->next = *a;
    else
        (*b)->next = 0;
    *a = *b;
    *b = save;
}

void    rotate_stack(t_stack **begin)
{
    t_stack *last;

    if (!begin || !(*begin)->next)
        return ;
    last = (*begin)->next;
    while (last->next)
        last = last->next;
    last->next = (*begin);
    *begin = (*begin)->next;
    last->next->next = 0;
}

void    reverse_rotate_stack(t_stack **begin)
{
    t_stack *last;
    t_stack *save;

    if (!begin || !(*begin)->next)
        return ;
    last = *begin;
    while (last->next && last->next->next)
        last = last->next;
    save = last->next;
    last->next = 0;
    save->next = *begin;
    *begin = save;
}