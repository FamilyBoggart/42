/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_calc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:34:33 by alerome2          #+#    #+#             */
/*   Updated: 2024/09/12 14:01:50 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	up_down_b(t_list *stack, int cont, t_list **temp)
{
	int	size;

	size = ft_lstsize(stack);
	if (cont >= (size / 2) + 1)
	{
		((t_stack *)(*temp)->content)->moves[2] = size - cont;
		((t_stack *)(*temp)->content)->moves[3] = 2;
	}
	else
	{
		((t_stack *)(*temp)->content)->moves[2] = cont;
		((t_stack *)(*temp)->content)->moves[3] = 1;
	}
}

void	up_down_a(t_list *stack, int cont, t_list **temp)
{
	int	size;

	size = ft_lstsize(stack);
	if (cont >= (size / 2) + 1)
	{
		((t_stack *)(*temp)->content)->moves[0] = size - cont;
		((t_stack *)(*temp)->content)->moves[1] = 2;
	}
	else
	{
		((t_stack *)(*temp)->content)->moves[0] = cont;
		((t_stack *)(*temp)->content)->moves[1] = 1;
	}
}

void	total_weight(t_list	**temp)
{
	int		mov_a;
	int		weight_a;
	int		mov_b;
	int		weight_b;

	weight_a = ((t_stack *)(*temp)->content)->moves[0];
	mov_a = ((t_stack *)(*temp)->content)->moves[1];
	weight_b = ((t_stack *)(*temp)->content)->moves[2];
	mov_b = ((t_stack *)(*temp)->content)->moves[3];
	if (mov_a == mov_b)
	{
		if (weight_a > weight_b)
			((t_stack *)(*temp)->content)->weight = weight_a;
		else
			((t_stack *)(*temp)->content)->weight = weight_b;
	}
	else
	{
		((t_stack *)(*temp)->content)->weight = weight_a + weight_b;
	}
}

void	count_movements(t_list *stack, t_list **t, int pos, int opt)
{
	t_list	*temp;
	int		cont;

	cont = 0;
	temp = stack;
	while (temp)
	{
		if (((t_stack *)temp->content)->pos == pos)
		{
			if (opt == 1)
				up_down_a(stack, cont, t);
			else
				up_down_b(stack, cont, t);
			break ;
		}
		cont++;
		temp = temp->next;
	}
}

void	weight(t_list *stack_a, t_list *stack_b)
{
	int		actualpos;
	int		nextpos;
	int		size;
	t_list	*temp;

	temp = stack_b;
	size = ft_lstsize(stack_a) + ft_lstsize(stack_b);
	while (temp)
	{
		actualpos = ((t_stack *)temp->content)->pos;
		nextpos = find_next_pos(stack_a, actualpos, size);
		count_movements(stack_a, &temp, nextpos, 1);
		count_movements(stack_b, &temp, actualpos, 2);
		total_weight(&temp);
		temp = temp->next;
	}
}
