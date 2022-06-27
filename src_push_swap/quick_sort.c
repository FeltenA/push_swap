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

int	quick_sort_b(t_stack **a, t_stack **b, int size)
{
	
}

int	quick_sort_a(t_stack **a, t_stack **b, int size)
{
	int	median;
	int	nb_elem;
	int	nb_rota;

	if (size <= 3)
	{
		sort_three_stack(a, size);
		return (1);
	}
	nb_elem = size;
	nb_rota = 0;
	median = get_median(a, size);
	while (nb_elem != size / 2 + size % 2)
	{
		if ((*a)->num < median && nb_elem--)
			run_command(a, b, "pb");
		else if (++nb_rota)
			run_command(a, 0 "ra");
	}
	while (nb_rota--)
		run_command(a, 0, "rra");
	return (quick_sort_a(a, b, size / 2 + size % 2)
			&& quick_sort_b(a, b, size / 2));
}
