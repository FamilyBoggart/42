/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusher.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:48:54 by alerome2          #+#    #+#             */
/*   Updated: 2024/09/11 13:55:29 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_from_b(t_list **stack_a, t_list **stack_b,t_list *t)
{
	int		weight_a;
	int		weight_b;
	
	weight_a = ((t_stack *)t->content)->moves[0];
	weight_b = ((t_stack *)t->content)->moves[2];
	if(weight_a == 0 && weight_b == 0)
	{
		exec_push(stack_a, stack_b,2);
		return;
	}
	if(((t_stack *)t->content)->moves[1] == ((t_stack *)t->content)->moves[3])
	{
		if(((t_stack *)t->content)->moves[1] == 1)
			exec_rotate(stack_a,stack_b,3);
		else
			exec_rev_rotate(stack_a,stack_b,3);
		weight_a--;
		weight_b--;
	}
	else
	{
		if(weight_a)
		{
			if(((t_stack *)t->content)->moves[1] == 1)
				exec_rotate(stack_a,stack_b,1);
			else
				exec_rev_rotate(stack_a,stack_b,1);
			weight_a--;
		}
		if(weight_b)
		{
			if(((t_stack *)t->content)->moves[3] == 1)
				exec_rotate(stack_a,stack_b,2);
			else
				exec_rev_rotate(stack_a,stack_b,2);
			weight_b--;
		}
	}		
	if(!weight_a && !weight_b)
		exec_push(stack_a, stack_b,2);
}