/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:44:57 by afelten           #+#    #+#             */
/*   Updated: 2022/06/27 16:41:48 by afelten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	run_ncommand(t_stack **a, t_stack **b, const char *com, int n);
void	run_command(t_stack **a, t_stack **b, const char *com);
int	get_median(t_stack *a, int size);
int	quick_sort_b(t_stack **a, t_stack **b, int size);

static void	sort_three_stack_a(t_stack **a, int size)
{
	if (size == 2)
	{
		if ((*a)->num > (*a)->next->num)
			run_command(a, 0, "sa");
	}
	else if (size == 3)
	{
		while (size != 3 || (*a)->num > (*a)->next->num
				|| (*a)->next->num > (*a)->next->next->num)
		{
			if (size == 3 && (*a)->num > (*a)->next->num)
				run_command(a, 0, "sa");
			else if (size == 3 && ((*a)->next->next->num < (*a)->num
						|| (*a)->next->next->num < (*a)->next->num))
			{
				run_command(a, 0, "ra");
				size--;
			}
			else if ((*a)->num > (*a)->next->num)
				run_command(a, 0, "sa");
			else if (size++)
				run_command(a, 0, "rra");
		}
	}
}

static void	sort_three_stack_b(t_stack **a, t_stack **b, int size)
{
	if (size == 1)
		run_command(a, b, "pa");
	else if (size == 2)
	{
		if ((*b)->num < (*b)->next->num)
			run_command(0, b, "sb");
		run_ncommand(a, b, "pa", 2);
	}
	else if (size == 3)
	{
		while (size || (*a)->num > (*a)->next->num)
		{
			if (size == 1 && (*a)->num > (*a)->next->num)
				run_command(a, 0, "sa");
			else if (size == 1 || (size >= 2 && (*b)->num > (*b)->next->num)
						|| (size == 3 && (*b)->next->next->num < (*b)->num))
			{
				run_command(a, 0, "pa");
				size--;
			}
			else
				run_command(0, b, "sb");
		}
	}
}

int	quick_sort_a(t_stack **a, t_stack **b, int size)
{
	int	median;
	int	nb_elem;
	int	nb_rota;

	if (size <= 3)
	{
		sort_three_stack_a(a, size);
		return (1);
	}
	nb_elem = size;
	nb_rota = 0;
	median = get_median(*a, size);
	while (nb_elem != size / 2 + size % 2)
	{
		if ((*a)->num < median && nb_elem--)
			run_command(a, b, "pb");
		else if (++nb_rota)
			run_command(a, 0, "ra");
	}
	while (nb_rota--)
		run_command(a, 0, "rra");
	return (quick_sort_a(a, b, size / 2 + size % 2)
			&& quick_sort_b(a, b, size / 2));
}

int	quick_sort_b(t_stack **a, t_stack **b, int size)
{
	int	median;
	int	nb_elem;
	int	nb_rota;

	if (size <= 3)
	{
		sort_three_stack_b(a, b, size);
		return (1);
	}
	nb_elem = size;
	nb_rota = 0;
	median = get_median(*b, size);
	while (nb_elem != size / 2)
	{
		if ((*b)->num >= median && nb_elem--)
			run_command(a, b, "pa");
		else if (++nb_rota)
			run_command(0, b, "rb");
	}
	while (nb_rota--)
		run_command(0, b, "rrb");
	return (quick_sort_a(a, b, size / 2 + size % 2)
			&& quick_sort_b(a, b, size / 2));
}