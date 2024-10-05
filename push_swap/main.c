/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 11:31:29 by alerome2          #+#    #+#             */
/*   Updated: 2024/10/05 09:43:34 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_node(int value)
{
	t_list	*wagon;
	t_stack	*pointer;

	wagon = malloc(sizeof(t_list));
	pointer = malloc(sizeof(t_stack));
	if (!wagon || !pointer)
	{
		if (wagon)
			free(wagon);
		if (pointer)
			free(pointer);
		return (NULL);
	}
	pointer->value = value;
	wagon->content = pointer;
	wagon->next = NULL;
	return (wagon);
}

void	free_all(t_list *obj_a, t_stack *obj_b)
{
	free_stack (obj_a);
	if (obj_b)
	{
		if (obj_b->moves)
		{
			free(obj_b->moves);
		}
		free(obj_b);
	}
}

t_list	*create_stack(int *array, int size)
{
	t_list	*stack_a;
	t_list	*wagon;

	stack_a = NULL;
	while (size--)
	{
		wagon = create_node(*array);
		if (!wagon)
		{
			free_stack(stack_a);
			return (NULL);
		}
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
		free(((t_stack *)temp->content)->moves);
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
	free(temp);
}
