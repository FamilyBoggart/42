/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 10:42:04 by alerome2          #+#    #+#             */
/*   Updated: 2024/09/21 12:32:21 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

char 	*create_instruction(char **arg, int argc)
{
	char	*str;
	int	i;

	i = 0;
	str = "./push_swap ";
	if(argc == 2)
		str = ft_strjoin(str, arg[i]);
	else
	{
		while(arg[i])
		{
			str = ft_strjoin(str, (const char *)arg[i]);
			str = ft_strjoin(str, " ");
			i++;
		}
	}
	str = ft_strjoin(str, " > result.txt");
	return (str);
}

int finalcheck(t_list *stack)
{
	int	aux;

	aux = ((t_stack *)stack->content)->value;
	stack = stack->next;
	while (stack)
	{
		if (aux < ((t_stack *)stack->content)->value)
			stack = stack->next;
		else
			return (0);
	}
	return (1);
}

int	openfile(int argc, char *argv[])
{
	int	fd;

	system((const char *)create_instruction(argv,argc));
	fd = open("result.txt", O_RDONLY);
	return(fd);
}

int	main(int argc, char *argv[])
{
	int		fd;
	char	**arg;
	char	*line;
	int		*array;
	int		aux;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = NULL;
	if (argc < 2)
		return(0);
	arg = ++argv;
	system((const char *)create_instruction(arg,argc));
	aux = 0;
	fd = open("result.txt", O_RDONLY);
	line = get_next_line(fd);
	
	array = check(arg, &argc, &aux);
	if(aux == 0)
		stack_a = create_stack(array, argc - 1);
	else
		stack_a = create_stack(array, argc);


	if(!ft_strncmp(line, "Error\n", 6))
	{
		ft_printf(line);
		free(line);
		close(fd);
		return(0);
	}
	

	while(line)
	{
		ft_printf("%s",line);
		read_instructions(&stack_a, &stack_b, line);
		free(line);
		line = get_next_line(fd);
	}
	
	if (finalcheck(stack_a))
		ft_printf("OK");
	else
		ft_printf("KO");
	
	free(line);
	close(fd);
	return (0);
}
