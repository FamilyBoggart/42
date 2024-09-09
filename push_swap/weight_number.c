/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weight_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:03:14 by alerome2          #+#    #+#             */
/*   Updated: 2024/09/09 21:22:59 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_min(t_list *stack, int prev_min, char *type)
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
			if(ft_strncmp(type, "value", 5) == 0)
				number = ((t_stack *)temp->content)->value;
			else if(ft_strncmp(type, "weight", 6) == 0)
				number = ((t_stack *)temp->content)->weight;
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
	min = find_min(stack,MIN_INT, "value");
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
					min = find_min(stack,min, "value") + 1;
				else
					min = find_min(stack,min, "value");
			}
			temp = temp->next;
		}
	}
}

int find_next_pos(t_list *stack, int pos, int size)
{
	t_list	*temp;
	int		prev_pos;
	int		aux;

	aux = pos;
	prev_pos = 0;
	while(aux++<size)
	{
		temp = stack;
		while(temp)
		{
			if (((t_stack *)temp->content)->pos == aux)
			{
				prev_pos = ((t_stack *)temp->content)->pos;
				break;
			}
			temp = temp->next;
		}
		if(prev_pos != 0)
			break;
	}
	if(pos == size)
		prev_pos = 1;
	return (prev_pos);
}



