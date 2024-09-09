/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weight_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:03:14 by alerome2          #+#    #+#             */
/*   Updated: 2024/09/09 14:08:54 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_min(t_list *stack, int prev_min)
{
	t_list	*temp;
	int		min;
	int		number;

	int size = ft_lstsize(stack);
	while(size--)
	{
		temp = stack;
		min = MAX_INT;
		while (temp)
		{
			number = ((t_stack *)temp->content)->value;
			if (number < min && (number > prev_min || number == MIN_INT))
				min = number;	
			temp = temp->next;
		}
	}

	
	return (min);
}

void find_pos(t_list *stack)
{
	t_list	*temp;
	int		pos;
	int		size;
	int		min;

	size = ft_lstsize(stack);
	min = find_min(stack,MIN_INT);
	pos = 1;
	while(size--)
	{
		temp = stack;
		while (temp)
		{
			if (((t_stack *)temp->content)->value == min)
			{
				((t_stack *)temp->content)->pos = pos;
				pos++;
				if (min == MIN_INT)
					min = find_min(stack,min) + 1;
				else
					min = find_min(stack,min);
			}
			temp = temp->next;
		}
	}
}

void show_pos(t_list *stack)
{
	find_pos(stack);
	while (stack)
	{
		ft_printf("NUmber: %d, pos: %d\n", ((t_stack *)stack->content)->value, ((t_stack *)stack->content)->pos);
		stack = stack->next;
	}
}

