/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 11:31:29 by alerome2          #+#    #+#             */
/*   Updated: 2024/09/20 12:56:07 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show(t_list *a, t_list *sb)
{
	ft_printf("\nStack a\n--------\n");
	while (a)
	{
		ft_printf("%d:\tpos: %d\tweight_a: %d\tdirection: %d\tweight_b: %d\t"
			"direction: %d\ttotal_weight: %d\n",
			((t_stack *)a->content)->value, ((t_stack *)a->content)->pos,
			((t_stack *)a->content)->moves[0],
			((t_stack *)a->content)->moves[1],
			((t_stack *)a->content)->moves[2],
			((t_stack *)a->content)->moves[3], ((t_stack *)a->content)->weight);
		a = a->next;
	}
	ft_printf("Stack b\n--------\n");
	while (sb)
	{
		ft_printf("%d:\tpos: %d\tweight_a: %d\tdirection: %d\tweight_b: %d\t"
			"direction: %d\ttotal_weight: %d\n",
			((t_stack *)sb->content)->value, ((t_stack *)sb->content)->pos,
			((t_stack *)sb->content)->moves[0],
			((t_stack *)sb->content)->moves[1],
			((t_stack *)sb->content)->moves[2],
			((t_stack *)sb->content)->moves[3],
			((t_stack *)sb->content)->weight);
		sb = sb->next;
	}
}

t_list	*create_stack(int *array, int size)
{
	t_list	*stack_a;
	t_list	*wagon;
	t_stack	*pointer;
	t_stack	number;

	stack_a = NULL;
	while (size--)
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

