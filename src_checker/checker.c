#include "checker.h"

void	run_command(t_stack **a, t_stack **b, const char *com);
int	ft_lstsize(t_stack *lst);
void	ft_lstclear(t_stack **lst);
char	*get_next_line(int fd);
void	free_commands(char **commands);
int get_commands(char ***commands);

int	check_sort(t_stack *a, t_stack *b)
{
	if (ft_lstsize(b))
		return (0);
	while (a && a->next)
	{
		if (a->num > a->next->num)
			return (0);
		a = a->next;
	}
	return (1);
}

void	execute_commands(t_stack **a, t_stack **b, char **commands)
{
	while (*commands)
	{
		run_command(a, b, *commands);
		commands++;
	}
}

void	end_msg(t_stack *a, t_stack *b)
{
	if (check_sort(a, b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	char	**commands;

	if (argc > 1)
	{
		a = 0;
		b = 0;
		commands = 0;
		if (!parse_input(argc, argv, &a) || !get_commands(&commands))
		{
			ft_lstclear(&a);
			free_commands(commands);
			write(2, "Error\n", 6);
			return (1);
		}
		execute_commands(&a, &b, commands);
		end_msg(a, b);
		free_commands(commands);
        ft_lstclear(&b);
		ft_lstclear(&a);
	}
	return (0);
}