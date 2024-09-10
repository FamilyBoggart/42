/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_calc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:34:33 by alerome2          #+#    #+#             */
/*   Updated: 2024/09/10 12:00:13 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int up_down(t_list *stack, int cont)
{
	int		size;

	size = ft_lstsize(stack);
	if (cont == 0)
		return (0);
	else if (cont >= (size / 2) + 1)
		cont = (size / 2) + 1 - cont + 1; //Hacia abajo
	else
		cont = cont; //Hacia arriba
	return (cont);
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
			return (up_down(stack_a, cont));
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
		ft_printf("pos: %d nextpos: %d\n", actualpos, nextpos);
		((t_stack *)temp->content)->weight = weight;
		temp = temp->next;
	}
}