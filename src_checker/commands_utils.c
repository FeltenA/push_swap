#include <stdlib.h>

int		ft_strcmp(const char *s1, const char *s2);

void	free_commands(char **commands)
{
	int	i;

	i = 0;
	if (!commands)
		return ;
	while (commands[i])
	{
		free(commands[i]);
		i++;
	}
	free(commands);
}

static int  check_command(char *command)
{
    int check;

    check = ft_strcmp(command, "sa\n") && ft_strcmp(command, "sb\n");
    check = check && ft_strcmp(command, "ss\n") && ft_strcmp(command, "pa\n");
    check = check && ft_strcmp(command, "pb\n") && ft_strcmp(command, "ra\n");
    check = check && ft_strcmp(command, "rb\n") && ft_strcmp(command, "rr\n");
    check = check && ft_strcmp(command, "rra\n") && ft_strcmp(command, "rrb\n");
    check = check && ft_strcmp(command, "rrr\n");
    return (check);
}

static int	add_command(char ***commands, char *command)
{
	char	**save;
	int	i;

	i = 0;
	while ((*commands)[i])
		i++;
	save = malloc((i + 2) * sizeof(char *));
	if (!save)
		return (0);
	i = 0;
	while ((*commands)[i])
	{
		save[i] = (*commands)[i];
		i++;
	}
	save[i] = command;
	save[i + 1] = 0;
	free(*commands);
	*commands = save;
	return (1);
}

int get_commands(char ***commands)
{
    char	*command;

	*commands = malloc(sizeof(char *));
	**commands = 0;
	if (!(*commands))
		return (0);
	while (command = get_next_line(0))
	{
        if (check_command(command))
        {
            free(command);
            return (0);
        }
		if (!add_command(commands, command))
			return (0);
	}
	return (1);
}