/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weight_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:03:14 by alerome2          #+#    #+#             */
/*   Updated: 2024/09/09 17:53:22 by alerome2         ###   ########.fr       */
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

int find_prev_pos(t_list *stack, int pos)
{
	t_list	*temp;
	int		prev_pos;
	int		aux;

	aux = pos;
	prev_pos = 0;
	while(aux--)
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
	return (prev_pos);
}

void	set_weight(t_list *stack_a, t_list *stack_b)
{
	int			actualpos;
	int			prevpos;

	actualpos = ((t_stack *)stack_b->content)->pos;
	prevpos = find_prev_pos(stack_a,actualpos);
	ft_printf("actualpos: %d\n",actualpos);
	ft_printf("prevpos: %d\n",prevpos);
}

