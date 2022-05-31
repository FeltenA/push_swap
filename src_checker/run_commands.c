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

#include "checker.h"
#include <unistd.h>

int		ft_strcmp(const char *s1, const char *s2);
void	swap_stack(t_stack **begin);
void	push_stack(t_stack **a, t_stack **b);
void	rotate_stack(t_stack **begin);
void	reverse_rotate_stack(t_stack **begin);

static void	run_command2(t_stack **a, t_stack **b, const char *com)
{
	if (!ft_strcmp(com, "pa\n"))
		push_stack(a, b);
	else if (!ft_strcmp(com, "pb\n"))
		push_stack(b, a);
	else if (!ft_strcmp(com, "rra\n"))
		reverse_rotate_stack(a);
	else if (!ft_strcmp(com, "rrb\n"))
		reverse_rotate_stack(b);
	else if (!ft_strcmp(com, "rrr\n"))
	{
		reverse_rotate_stack(a);
		reverse_rotate_stack(b);
	}
}

void	run_command(t_stack **a, t_stack **b, const char *com)
{
	if (!ft_strcmp(com, "sa\n"))
		swap_stack(a);
	else if (!ft_strcmp(com, "sb\n"))
		swap_stack(b);
	else if (!ft_strcmp(com, "ss\n"))
	{
		swap_stack(a);
		swap_stack(b);
	}
	else if (!ft_strcmp(com, "ra\n"))
		rotate_stack(a);
	else if (!ft_strcmp(com, "rb\n"))
		rotate_stack(b);
	else if (!ft_strcmp(com, "rr\n"))
	{
		rotate_stack(a);
		rotate_stack(b);
	}
	else
		run_command2(a, b, com);
}