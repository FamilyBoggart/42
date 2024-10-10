/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 10:42:04 by alerome2          #+#    #+#             */
/*   Updated: 2024/10/10 11:51:46 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_instruction(char **arg, int argc)
{
	char	*str;
	int		i;

	i = 0;
	str = "";
	if (argc == 2)
		str = ft_strjoin("./push swap", arg[i], 0);
	else
	{
		while (arg[i])
		{
			str = ft_strjoin(str, arg[i], 1);
			str = ft_strjoin(str, " ", 1);
			i++;
		}
	}
	str = ft_strjoin(str, " > result.txt", 1);
	system(str);
	free(str);
}

void	finalcheck(t_list *stack)
{
	int	aux;
	int	boolean;

	boolean = 1;
	aux = ((t_stack *)stack->content)->value;
	stack = stack->next;
	while (stack)
	{
		if (aux < ((t_stack *)stack->content)->value)
			stack = stack->next;
		else
			boolean = 0;
	}
	if (boolean == 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

t_list	*first_stack(int argc, char *argv[])
{
	int		*array;
	int		aux;
	t_list	*stack_a;

	aux = 0;
	array = check(argv, &argc, &aux);
	if (aux == 0)
		stack_a = create_stack(array, argc - 1);
	else
		stack_a = create_stack(array, argc);
	free(array);
	return (stack_a);
}

int	main(int argc, char *argv[])
{
	int		fd;
	char	*line;
	t_list	*stack_a;
	t_list	*stack_b;

	create_instruction(++argv, argc);
	fd = open("result.txt", O_RDONLY);
	line = get_next_line(fd);
	stack_a = first_stack(argc, argv);
	if (!ft_strncmp(line, "Error\n", 6))
	{
		ft_printf(line);
		free_stack(stack_a);
		return (closefile(fd, line));
	}
	stack_b = NULL;
	while (line)
	{
		read_instructions(&stack_a, &stack_b, line);
		free(line);
		line = get_next_line(fd);
	}
	finalcheck(stack_a);
	free_stack(stack_a);
	return (closefile(fd, line));
}
