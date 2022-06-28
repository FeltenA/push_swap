/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:10:08 by afelten           #+#    #+#             */
/*   Updated: 2022/06/27 15:18:34 by afelten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_median_up(t_stack *a, int num, int size)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	while (i < size && a)
	{
		if (a->num > num)
			nbr++;
		i++;
		a = a->next;
	}
	return (nbr);
}

static int	check_median_down(t_stack *a, int num, int size)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	while (i < size && a)
	{
		if (a->num < num)
			nbr++;
		i++;
		a = a->next;
	}
	return (nbr);
}

int	get_median(t_stack *a, int size)
{
	t_stack	*save;
	int	i;
	int	save_nbr_up;
	int	save_nbr_down;

	i = 0;
	save = a;
	while (a && i < size)
	{
		save_nbr_up = check_median_up(save, a->num, size);
		save_nbr_down = check_median_down(save, a->num, size);
		if (save_nbr_down == save_nbr_up || save_nbr_down - 1 == save_nbr_up)
			return (a->num);
		i++;
		a = a->next;
	}
	return (0);
}
