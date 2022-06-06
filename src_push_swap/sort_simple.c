/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:00:03 by afelten           #+#    #+#             */
/*   Updated: 2022/06/06 18:22:34 by afelten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_lstsize(t_stack *lst);
void	run_command(t_stack **a, t_stack **b, const char *com);
void	run_ncommand(t_stack **a, t_stack **b, const char *com, int n);
void	get_nbr_to_top(t_stack **a, int nbr);
void	get_min_to_top(t_stack **a);

void	sort_three(t_stack **a)
{
	t_stack	*second;
	t_stack	*third;

	second = (*a)->next;
	third = (*a)->next->next;
	if ((*a)->num > second->num && second->num < third->num
		&& third->num > (*a)->num)
		run_command(a, 0, "sa");
	else if ((*a)->num > second->num && second->num > third->num)
	{
		run_command(a, 0, "sa");
		run_command(a, 0, "rra");
	}
	else if ((*a)->num > second->num && second->num < third->num
		&& third->num < (*a)->num)
		run_command(a, 0, "ra");
	else if ((*a)->num < second->num && second->num > third->num
		&& third->num > (*a)->num)
	{
		run_command(a, 0, "sa");
		run_command(a, 0, "ra");
	}
	else if ((*a)->num < second->num && second->num > third->num
		&& third->num < (*a)->num)
		run_command(a, 0, "rra");
}

void	sort_small(t_stack **a, t_stack **b, int size)
{
	int	i;

	i = 0;
	run_ncommand(a, b, "pb", size - 3);
	sort_three(a);
	while (i < size - 3)
	{
		get_nbr_to_top(a, (*b)->num);
		run_command(a, b, "pa");
		get_min_to_top(a);
		i++;
	}
}

void	sort_simple(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (size == 2 && (*a)->num > (*a)->next->num)
		run_command(a, b, "sa");
	else if (size == 3)
		sort_three(a);
	else
		sort_small(a, b, size);
}
