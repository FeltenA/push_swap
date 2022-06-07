/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:47:42 by afelten           #+#    #+#             */
/*   Updated: 2022/06/07 12:19:28 by afelten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_lstsize(t_stack *lst);
void	run_ncommand(t_stack **a, t_stack **b, const char *com, int n);
void	run_command(t_stack **a, t_stack **b, const char *com);

int	get_last_index_chunk(t_stack *a, int max, int step)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (a)
	{
		if (a->num >= max - step && a->num <= max)
			index = i;
		i++;
		a = a->next;
	}
	return (index);
}

int	get_first_index_chunk(t_stack *a, int max, int step)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->num >= max - step && a->num <= max)
			return (i);
		i++;
		a = a->next;
	}
	return (0);
}

void	get_closest_chunk(t_stack **a, t_stack **b, int max, int step)
{
	int	i_first;
	int	i_last;
	int	size;

	size = ft_lstsize(*a);
	i_first = get_first_index_chunk(*a, max, step);
	i_last = get_last_index_chunk(*a, max, step);
	if (i_first > size - i_last)
		run_ncommand(a, 0, "rra", size - i_last);
	else
		run_ncommand(a, 0, "ra", i_first);
	run_command(a, b, "pb");
}

int	chunk_left(t_stack *a, int max, int step)
{
	while (a)
	{
		if (a->num >= max - step && a->num <= max)
			return (1);
		a = a->next;
	}
	return (0);
}

int	check_non_chunk(t_stack *a, int max)
{
	int	nbr;

	nbr = 0;
	while (a)
	{
		if (a->num <= max)
			nbr++;
		a = a->next;
	}
	return (nbr);
}
