#include "push_swap.h"

int	ft_lstsize(t_stack *lst);
void    run_command(t_stack **a, t_stack **b, const char *com);
void    run_ncommand(t_stack **a, t_stack **b, const char *com, int n);
int get_max_stack(t_stack *a);
int get_min_stack(t_stack *a);
void    get_min_to_top(t_stack **a);
int chunk_left(t_stack *a, int max, int step);
void    get_closest_chunk(t_stack **a, t_stack **b, int max, int step);
void    get_min_or_max_to_top(t_stack **b);
void    get_nbr_to_top(t_stack **a, int nbr);
int check_non_chunk(t_stack *a, int max);

int check_step_stack(t_stack *a, int max, int step)
{
    int nbr;

    nbr = 0;
    while (a)
    {
        if (a->num >= max - step && a->num <= max)
            nbr++;
        a = a->next;
    }
    return (nbr);
}

void get_chunk_step(t_stack *a, int max, int *step, int size)
{
    int nbr;
    int check;

    nbr = 0;
    check = check_non_chunk(a, max);
    if (check < size)
        size = check;
    while (nbr < size || nbr > size + 5)
    {
        nbr = check_step_stack(a, max, *step);
        if (nbr < size)
            *step += 5;
        else if (nbr > size + 5)
            *step -= 5;
    }
}

void    sort_chunk(t_stack **a, t_stack **b, t_chunk chunk, int *lastnbr)
{
    int size;

    while (chunk_left(*a, chunk.max, chunk.step))
        get_closest_chunk(a, b, chunk.max, chunk.step);
    size = ft_lstsize(*b);
    if (*lastnbr != -2147483648)
        get_nbr_to_top(a, *lastnbr);
    while (size)
    {
        get_min_or_max_to_top(b);
        if ((*a) && (*a)->num < (*b)->num)
            run_command(a, 0, "ra");
        *lastnbr = (*b)->num;
        run_command(a, b, "pa");
        size--;
    }
}

void    sort_complex(t_stack **a, t_stack **b, int size)
{
    t_chunk chunk;
    int min;
    int lastnbr;

    lastnbr = -2147483648;
    chunk.size = 40;
    if (size < chunk.size)
        chunk.size = size;
    chunk.step = chunk.size + 1;
    chunk.max = get_max_stack(*a);
    min = get_min_stack(*a);
    get_chunk_step(*a, chunk.max, &(chunk.step), chunk.size);
    while (chunk.max > min)
    {
        sort_chunk(a, b, chunk, &lastnbr);
        chunk.max = chunk.max - chunk.step - 1;
        if (chunk.max > min)
            get_chunk_step(*a, chunk.max, &(chunk.step), chunk.size);
    }
    get_min_to_top(a);
}