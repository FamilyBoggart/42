/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weight_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:03:14 by alerome2          #+#    #+#             */
/*   Updated: 2024/10/05 12:49:31 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_list *stack, int prev_min, char *type)
{
	t_list	*temp;
	int		min;
	int		number;
	int		size;

	size = ft_lstsize(stack);
	while (size--)
	{
		temp = stack;
		min = MAX_INT;
		while (temp)
		{
			if (ft_strncmp(type, "value", 5) == 0)
				number = ((t_stack *)temp->content)->value;
			else if (ft_strncmp(type, "pos", 6) == 0)
				number = ((t_stack *)temp->content)->pos;
			if (number < min && (number > prev_min || number == MIN_INT))
				min = number;
			temp = temp->next;
		}
	}
	return (min);
}

void	find_pos(t_list *stack)
{
	t_list	*temp;
	int		pos;
	int		size;
	int		min;

	size = ft_lstsize(stack);
	min = find_min(stack, MIN_INT, "value");
	pos = 1;
	while (size--)
	{
		temp = stack;
		while (temp)
		{
			if (((t_stack *)temp->content)->value == min)
			{
				((t_stack *)temp->content)->pos = pos;
				pos++;
				if (min == MIN_INT)
					min = find_min(stack, min, "value") + 1;
				else
					min = find_min(stack, min, "value");
			}
			temp = temp->next;
		}
	}
}

int	find_max_pos(t_list *stack)
{
	t_list	*temp;
	int		max;

	temp = stack;
	max = 0;
	while (temp)
	{
		if (((t_stack *)temp->content)->pos > max)
			max = ((t_stack *)temp->content)->pos;
		temp = temp->next;
	}
	return (max);
}

int	find_next_pos(t_list *stack, int pos, int size)
{
	t_list	*temp;
	int		next_pos;
	int		aux;

	aux = pos;
	next_pos = 0;
	while (aux++ < size)
	{
		temp = stack;
		while (temp)
		{
			if (((t_stack *)temp->content)->pos == aux)
			{
				next_pos = ((t_stack *)temp->content)->pos;
				break ;
			}
			temp = temp->next;
		}
		if (next_pos != 0)
			break ;
	}
	if (pos > find_max_pos(stack))
		next_pos = find_min(stack, MIN_INT, "pos");
	return (next_pos);
}
