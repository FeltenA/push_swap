/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:56:38 by afelten           #+#    #+#             */
/*   Updated: 2022/05/24 13:59:26 by afelten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_lstsize(t_stack *lst);
void	run_ncommand(t_stack **a, t_stack **b, const char *com, int n);

int	get_max_stack(t_stack *a)
{
	int	save;

	save = a->num;
	while (a)
	{
		if (a->num > save)
			save = a->num;
		a = a->next;
	}
	return (save);
}

int	get_min_stack(t_stack *a)
{
	int	save;

	save = a->num;
	while (a)
	{
		if (a->num < save)
			save = a->num;
		a = a->next;
	}
	return (save);
}

void	get_nbr_to_top(t_stack **a, int nbr)
{
	int		size;
	int		i;
	t_stack	*save;

	save = *a;
	size = ft_lstsize(*a);
	i = 0;
	while (save && save->num < nbr)
	{
		i++;
		save = save->next;
	}
	if (i > size / 2)
		run_ncommand(a, 0, "rra", size - i);
	else
		run_ncommand(a, 0, "ra", i);
}

void	get_min_to_top(t_stack **a)
{
	int		size;
	int		i;
	int		nbr;
	t_stack	*save;

	nbr = get_min_stack(*a);
	save = *a;
	size = ft_lstsize(*a);
	i = 0;
	while (save && save->num > nbr)
	{
		i++;
		save = save->next;
	}
	if (i > size / 2)
		run_ncommand(a, 0, "rra", size - i);
	else
		run_ncommand(a, 0, "ra", i);
}
