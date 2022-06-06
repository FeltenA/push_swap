/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:06:11 by afelten           #+#    #+#             */
/*   Updated: 2022/06/06 16:53:44 by afelten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack	*ft_lstnew(int num);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
int		compare_num_stack(t_stack *begin, int num);

int	atoi_check(const char *nptr, int *check)
{
	long	nbr;
	int		neg;

	nbr = 0;
	neg = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			neg = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		nbr = nbr * 10 + *nptr - 48;
		if (nbr * neg > 2147483647 || nbr * neg < -2147483648)
			*check = 0;
		nptr++;
	}
	return (nbr * neg);
}

int	check_num(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int	parse_input_str(char *str, t_stack **a)
{
	int		check;
	t_stack	*save;

	check = 1;
	while (*str)
	{
		if (*str == ' ')
			str++;
		if ((*str >= '0' && *str <= '9') || *str == '-' || *str == '+')
		{
			save = ft_lstnew(atoi_check(str, &check));
			if (check && save && compare_num_stack(*a, save->num))
				check = 0;
			ft_lstadd_back(a, save);
			if (!check || !save)
				return (0);
			if (*str == '-' || *str == '+')
				str++;
			while (*str >= '0' && *str <= '9')
				str++;
		}
		if (*str && *str != ' ')
			return (0);
	}
	return (1);
}

int	parse_input(int argc, char *argv[], t_stack **a)
{
	int		i;
	int		check;
	t_stack	*save;

	i = 0;
	if (argc > 2)
	{
		check = 1;
		while (++i < argc)
		{
			if (!check_num(argv[i]))
				return (0);
			save = ft_lstnew(atoi_check(argv[i], &check));
			if (check && save && compare_num_stack(*a, save->num))
				check = 0;
			ft_lstadd_back(a, save);
			if (!check || !save)
				return (0);
		}
	}
	else
		return (parse_input_str(argv[1], a));
	return (1);
}
