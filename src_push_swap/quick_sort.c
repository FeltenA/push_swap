/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:44:57 by afelten           #+#    #+#             */
/*   Updated: 2022/09/17 15:55:00 by afelten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	run_ncommand(t_stack **a, t_stack **b, const char *com, int n);
void	run_command(t_stack **a, t_stack **b, const char *com);
int		get_median(t_stack *a, int size);
int		quick_sort_b(t_stack **a, t_stack **b, int size);
int		is_sorted_asc(t_stack *a, int size);
int		is_sorted_desc(t_stack *a, int size);
int		ft_lstsize(t_stack *a);

static int	sort_three_stack_a(t_stack **a, int size)
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
			if ((*a)->num > (*a)->next->num)
				run_command(a, 0, "sa");
			else if (size == 3 && ((*a)->next->next->num < (*a)->num
					|| (*a)->next->next->num < (*a)->next->num))
			{
				run_command(a, 0, "ra");
				size--;
			}
			else if (size++)
				run_command(a, 0, "rra");
		}
	}
	return (1);
}

static int	sort_three_stack_b(t_stack **a, t_stack **b, int size)
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
		while (size)
		{
			if (size == 1 && (*a)->num > (*a)->next->num)
				run_command(a, 0, "sa");
			else if (size > 1 && (*b)->num < (*b)->next->num)
				run_command(0, b, "sb");
			else
			{
				run_command(a, b, "pa");
				size--;
			}
		}
	}
	return (1);
}

int	quick_sort_a(t_stack **a, t_stack **b, int size)
{
	int	median;
	int	nb_elem;
	int	nb_rota;

	if (is_sorted_asc(*a, size))
		return (1);
	if (size <= 3)
		return (sort_three_stack_a(a, size));
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
	if (ft_lstsize(*a) != size / 2 + size % 2)
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

	if (is_sorted_desc(*b, size))
		while (size--)
			run_command(a, b, "pa");
	if (size <= 3)
		return (sort_three_stack_b(a, b, size));
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
	if (ft_lstsize(*b) != size / 2)
		while (nb_rota--)
			run_command(0, b, "rrb");
	return (quick_sort_a(a, b, size / 2 + size % 2)
		&& quick_sort_b(a, b, size / 2));
}
