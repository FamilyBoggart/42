/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusher.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:48:54 by alerome2          #+#    #+#             */
/*   Updated: 2024/09/11 17:37:16 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	weight_zero(int weight_a, int weight_b, int mov_a, int mov_b)
{
	if (weight_a == 0 && weight_b == 0)
		return (1);
	else if (weight_a == 0)
	{
		if (mov_b == 1)
			return (2);
		else if (mov_b == 2)
			return (3);
	}
	else if (weight_b == 0)
	{
		if (mov_a == 1)
			return (4);
		else if (mov_a == 2)
			return (5);
	}
	return (0);
}

int by_mov(int mov_a, int mov_b)
{
	if(mov_a == mov_b && mov_a == 1)
		return(6);
	else if(mov_a == mov_b && mov_a == 2)
		return(7);
	else if(mov_a == 1)
		return(4);
	else if(mov_a == 2)
		return(5);
	else
		return(0);
	
}

void execute_move(t_list **stack_a, t_list **stack_b, int opt)
{
	if(opt == 1)
		exec_push(stack_a, stack_b, 2);
	else if(opt == 2)
		exec_rotate(stack_a, stack_b, 2);
	else if(opt == 3)
		exec_rev_rotate(stack_a, stack_b, 2);
	else if(opt == 4)
		exec_rev_rotate(stack_a, stack_b, 1);
	else if(opt == 5)
		exec_rotate(stack_a, stack_b, 1);
	else if(opt == 6)
		exec_rotate(stack_a, stack_b, 3);
	else if(opt == 7)
		exec_rev_rotate(stack_a, stack_b, 3);
}

void	push_from_b(t_list **stack_a, t_list **stack_b,t_list *t)
{
	int	weight_a;
	int	weight_b;
	int	mov_a;
	int	mov_b;
	int	opt;

	weight_a = ((t_stack *)t->content)->moves[0];
	weight_b = ((t_stack *)t->content)->moves[2];
	mov_a = ((t_stack *)t->content)->moves[1];
	mov_b = ((t_stack *)t->content)->moves[3];
	opt = weight_zero(weight_a, weight_b, mov_a, mov_b);
	if (opt == 0)
		opt = by_mov(mov_a, mov_b);
	execute_move(stack_a, stack_b, opt);	
}
