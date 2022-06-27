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

static int	check_median(t_stack *a, int num, int size)
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

int	get_median(t_stack *a, int size)
{
	int	i;
	int	save;
	int	save_nbr;
	int	new_nbr;

	i = 0;
	save = a->num;
	save_nbr = check_median(a, a->num, size);
	while (a && i < size)
	{
		new_nbr = check_median(a, a->num, size);
		if (save_nbr < new_nbr)
		{
			save_nbr = new_nbr;
			save = a->num;
		}
		i++;
		a = a->next;
	}
	return (save);
}
