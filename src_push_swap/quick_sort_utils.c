/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:48:27 by afelten           #+#    #+#             */
/*   Updated: 2022/09/17 15:48:31 by afelten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted_asc(t_stack *a, int size)
{
	int	i;

	i = 0;
	while (i < size - 1 && a && a->next)
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
	while (i < size - 1 && a && a->next)
	{
		if (a->num < a->next->num)
			return (0);
		a = a->next;
		i++;
	}
	return (1);
}
