/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:39:51 by afelten           #+#    #+#             */
/*   Updated: 2022/06/07 13:52:54 by afelten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

int		parse_input(int argc, char *argv[], t_stack **a);
void	ft_lstclear(t_stack **lst);
int		ft_lstsize(t_stack *lst);
void	sort_simple(t_stack **a, t_stack **b);
void	sort_complex(t_stack **a, t_stack **b, int size);

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	if (argc > 1)
	{
		size = 0;
		a = 0;
		b = 0;
		if (!parse_input(argc, argv, &a))
		{
			ft_lstclear(&a);
			write(2, "Error\n", 6);
			return (1);
		}
		size = ft_lstsize(a);
		if (ft_lstsize(a) <= 5)
			sort_simple(&a, &b);
		else if (ft_lstsize(a) > 5)
			sort_complex(&a, &b, size);
		ft_lstclear(&a);
	}
	return (0);
}
