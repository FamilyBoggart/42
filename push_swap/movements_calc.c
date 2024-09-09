/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_calc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:34:33 by alerome2          #+#    #+#             */
/*   Updated: 2024/09/09 21:24:22 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int upper(t_list *stack, int cont)
{
	if (cont != 0)
	{
		if (cont > ft_lstsize(stack) / 2)
			return (ft_lstsize(stack) - cont);
		else
			return (cont);
	}
	else
		return (0);
	}

int count_movements_a(t_list *stack_a, int nextpos)
{
	t_list	*temp;
	int		cont;

	cont = 0;
	temp = stack_a;
	while(temp)
	{
		if (((t_stack *)temp->content)->pos == nextpos)
		{
			return (upper(stack_a, cont));
		}
		cont++;
		temp = temp->next;
	}
	return (cont);
}

void weight(t_list *stack_a, t_list *stack_b)
{
	int		actualpos;
	int		nextpos;
	int		weight;
	int 	size;
	t_list	*temp;

	temp = stack_b;
	size = ft_lstsize(stack_a) + ft_lstsize(stack_b);
	while (temp)
	{
		actualpos = ((t_stack *)temp->content)->pos;
		nextpos = find_next_pos(stack_a, actualpos, size);
		weight = count_movements_a(stack_a, nextpos);
		((t_stack *)temp->content)->weight = weight;
		temp = temp->next;
	}
}