#include "push_swap.h"

int	ft_lstsize(t_stack *lst);
void    run_ncommand(t_stack **a, t_stack **b, const char *com, int n);

int get_max_stack_index(t_stack *a)
{
    int save;
    int i;
    int index;

    save = a->num;
    i = 0;
    index = 0;
    while (a)
    {
        if (a->num > save)
        {
            index = i;
            save = a->num;
        }
        i++;
        a = a->next;
    }
    return (index);
}

int get_min_stack_index(t_stack *a)
{
    int save;
    int i;
    int index;

    save = a->num;
    i = 0;
    index = 0;
    while (a)
    {
        if (a->num < save)
        {
            index = i;
            save = a->num;
        }
        i++;
        a = a->next;
    }
    return (index);
}

void    get_min_or_max_to_top(t_stack **b)
{
    int i_min;
    int i_max;
    int size;

    i_min = get_min_stack_index(*b);
    i_max = get_max_stack_index(*b);
    size = ft_lstsize(*b);
    if (i_min > size / 2 && ((i_max > size / 2 && i_min > i_max) || (i_max <= size / 2 && i_max > size - i_min)))
        run_ncommand(0, b, "rrb", size - i_min);
    else if (i_max > size / 2 && ((i_min > size / 2 && i_min < i_max) || (i_min <= size / 2 && i_min > size - i_max)))
        run_ncommand(0, b, "rrb", size - i_max);
    else if (i_min <= size / 2 && ((i_max <= size / 2 && i_min < i_max) || (i_max > size / 2 && i_min < size - i_max)))
        run_ncommand(0, b, "rb", i_min);
    else
        run_ncommand(0, b, "rb", i_max);
}