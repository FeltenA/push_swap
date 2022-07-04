#include "push_swap.h"

int	is_sorted_asc(t_stack *a, int size)
{
	int	i;

	i = 0;
	while (i < size && a && a->next)
	{
		if (a->num > a->next->num)
			return (0);
		a = a->next;
		i++;
	}
	return (1);
}

int	is_sorted_desc(t_stack *a, int size)
{
	int	i;

	i = 0;
	while (i < size && a && a->next)
	{
		if (a->num < a->next->num)
			return (0);
		a = a->next;
		i++;
	}
	return (1);
}
