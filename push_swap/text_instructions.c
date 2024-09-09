/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:54:48 by alerome2          #+#    #+#             */
/*   Updated: 2024/09/09 17:06:58 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_swap(t_list **stack, int option)
{
	if(option == 1)
	{
		swap(stack);
		ft_printf("sa\n");
	}
	if (option == 2)
	{
		swap(stack);
		ft_printf("sb\n");
	}
	if (option == 3)
	{
		swap(stack);
		ft_printf("ss\n");
	}	
}

void	exec_push(t_list **stack_a, t_list **stack_b, int option)
{
	if(option == 1)
	{
		push_a(stack_a, stack_b);
		ft_printf("pb\n");
	}
	if (option == 2)
	{
		push_b(stack_a, stack_b);
		ft_printf("pa\n");
	}
}

void	exec_rotate(t_list **stack, int option)
{
	if(option == 1)
	{
		rotate(stack);
		ft_printf("ra\n");
	}
	if (option == 2)
	{
		rotate(stack);
		ft_printf("rb\n");
	}
	if (option == 3)
	{
		rotate(stack);
		ft_printf("rr\n");
	}
}

void	exec_rev_rotate(t_list **stack, int option)
{
	if(option == 1)
	{
		rev_rotate(stack);
		ft_printf("rra\n");
	}
	if (option == 2)
	{
		rev_rotate(stack);
		ft_printf("rrb\n");
	}
	if (option == 3)
	{
		rev_rotate(stack);
		ft_printf("rrr\n");
	}
}