/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:44:11 by afelten           #+#    #+#             */
/*   Updated: 2022/05/24 13:47:21 by afelten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

int		ft_strcmp(const char *s1, const char *s2);
void	swap_stack(t_stack **begin);
void	push_stack(t_stack **a, t_stack **b);
void	rotate_stack(t_stack **begin);
void	reverse_rotate_stack(t_stack **begin);

static void	run_command2(t_stack **a, t_stack **b, const char *com)
{
	if (!ft_strcmp(com, "pa"))
	{
		push_stack(a, b);
		write(1, "pa\n", 3);
	}
	else if (!ft_strcmp(com, "pb"))
	{
		push_stack(b, a);
		write(1, "pb\n", 3);
	}
	else if (!ft_strcmp(com, "rra"))
	{
		reverse_rotate_stack(a);
		write(1, "rra\n", 4);
	}
	else if (!ft_strcmp(com, "rrb"))
	{
		reverse_rotate_stack(b);
		write(1, "rrb\n", 4);
	}
}

void	run_command(t_stack **a, t_stack **b, const char *com)
{
	if (!ft_strcmp(com, "sa"))
	{
		swap_stack(a);
		write(1, "sa\n", 3);
	}
	else if (!ft_strcmp(com, "sb"))
	{
		swap_stack(b);
		write(1, "sb\n", 3);
	}
	else if (!ft_strcmp(com, "ra"))
	{
		rotate_stack(a);
		write(1, "ra\n", 3);
	}
	else if (!ft_strcmp(com, "rb"))
	{
		rotate_stack(b);
		write(1, "rb\n", 3);
	}
	else
		run_command2(a, b, com);
}

void	run_ncommand(t_stack **a, t_stack **b, const char *com, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		run_command(a, b, com);
}
