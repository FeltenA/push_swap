/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:42:36 by afelten           #+#    #+#             */
/*   Updated: 2022/06/06 16:04:04 by afelten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

t_stack	*ft_lstnew(int num)
{
	t_stack	*elem;

	elem = malloc(sizeof(t_stack));
	if (!elem)
		return (0);
	elem->num = num;
	elem->next = 0;
	return (elem);
}

int	ft_lstsize(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	ft_lstclear(t_stack **lst)
{
	t_stack	*elem;

	while (*lst)
	{
		elem = *lst;
		*lst = (*lst)->next;
		free(elem);
	}
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*elem;

	elem = *lst;
	if (!elem)
	{
		*lst = new;
		return ;
	}
	while (elem->next)
		elem = elem->next;
	elem->next = new;
}

int	compare_num_stack(t_stack *begin, int num)
{
	while (begin)
	{
		if (begin->num == num)
			return (1);
		begin = begin->next;
	}
	return (0);
}
