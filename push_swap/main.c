/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 11:31:29 by alerome2          #+#    #+#             */
/*   Updated: 2024/09/12 11:19:36 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
void	show(t_list *stack_a, t_list *stack_b)
{
	ft_printf("\nStack a\n--------\n");
	while (stack_a)
	{
		ft_printf("%d:\tpos: %d\tweight_a: %d\tdirection: %d\tweight_b: %d\tdirection: %d\ttotal_weight: %d\n", ((t_stack *)stack_a->content)->value, ((t_stack *)stack_a->content)->pos, ((t_stack *)stack_a->content)->moves[0], ((t_stack *)stack_a->content)->moves[1], ((t_stack *)stack_a->content)->moves[2], ((t_stack *)stack_a->content)->moves[3], ((t_stack *)stack_a->content)->weight);
		stack_a = stack_a->next;	
	}
	ft_printf("Stack b\n--------\n");
	while (stack_b)
	{
		ft_printf("%d:\tpos: %d\tweight_a: %d\tdirection: %d\tweight_b: %d\tdirection: %d\ttotal_weight: %d\n", ((t_stack *)stack_b->content)->value, ((t_stack *)stack_b->content)->pos, ((t_stack *)stack_b->content)->moves[0], ((t_stack *)stack_b->content)->moves[1], ((t_stack *)stack_b->content)->moves[2], ((t_stack *)stack_b->content)->moves[3], ((t_stack *)stack_b->content)->weight);
		stack_b = stack_b->next;	
	}
}
*/

#include "push_swap.h"

t_list	*create_stack(int *array)
{
	t_list	*stack_a;
	t_list	*wagon;
	t_stack	*pointer;
	t_stack	number;

	stack_a = NULL;
	while (*array)
	{
		wagon = malloc(sizeof(t_list));
		pointer = malloc(sizeof(t_stack));
		if (!wagon || !pointer)
		{
			free(wagon);
			free(pointer);
			free(array);
			return (NULL);
		}
		number.value = *array;
		*pointer = number;
		wagon->content = pointer;
		wagon->next = NULL;
		ft_lstadd_back(&stack_a, wagon);
		array++;
	}
	return (stack_a);
}

void	free_stack(t_list *stack)
{
	t_list	*temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp->content);
		free(temp);
	}
}

void	set_default_moves(t_list *stack)
{
	t_list	*temp;

	temp = stack;
	while (temp)
	{
		((t_stack *)temp->content)->moves = calloc(4, sizeof(int));
		temp = temp->next;
	}
}

int	main(int argc, char *argv[])
{
	int		*array;
	int		i;
	t_list	*stack_a;
	t_list	*stack_b;

	i = 1;
	array = malloc((argc - 1) * sizeof(int));
	if (argc < 2 || !array)
	{
		free(array);
		ft_printf("Error");
		return (0);
	}
	while (argv[i])
	{
		array[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	stack_a = create_stack(array);
	stack_b = NULL;
	find_pos(stack_a);
	set_default_moves(stack_a);
	sort(stack_a, stack_b);
	free_stack(stack_a);
	free(array);
}
