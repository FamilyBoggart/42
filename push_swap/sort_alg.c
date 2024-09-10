/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_alg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:08:11 by alerome2          #+#    #+#             */
/*   Updated: 2024/09/10 11:59:53 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show(t_list *stack_a, t_list *stack_b)
{
	ft_printf("\nStack a\n--------\n");
	while (stack_a)
	{
		ft_printf("%d:\tpos: %d\tweight: %d\n", ((t_stack *)stack_a->content)->value, ((t_stack *)stack_a->content)->pos, ((t_stack *)stack_a->content)->weight);
		stack_a = stack_a->next;	
	}
	ft_printf("Stack b\n--------\n");
	while (stack_b)
	{
		ft_printf("%d:\tpos: %d\tweight: %d\n", ((t_stack *)stack_b->content)->value, ((t_stack *)stack_b->content)->pos, ((t_stack *)stack_b->content)->weight);
		stack_b = stack_b->next;	
	}
}

void	sort_3(t_list **stack)
{
	int	s1;
	int	s2;
	int	s3;

	s1 = ((t_stack *)(*stack)->content)->value;
	s2 = ((t_stack *)(*stack)->next->content)->value;
	s3 = ((t_stack *)(*stack)->next->next->content)->value;
	if (s1 < s2 && s2 > s3 && s1 < s3)
	{
		exec_swap(stack,1);
		exec_rev_rotate(stack,1);
	}
	else if (s1 > s2 && s2 < s3 && s1 < s3)
		exec_swap(stack,1);
	else if (s1 > s2 && s2 < s3 && s1 > s3)
		exec_rev_rotate(stack,1);
	else if (s1 < s2 && s2 > s3 && s1 > s3)
		exec_rotate(stack,1);
	else if (s1 > s2 && s2 > s3)
	{
		exec_swap(stack,1);
		exec_rotate(stack,1);
	}
}

void	sort_2(t_list **stack)
{
	if (((t_stack *)(*stack)->content)->value > ((t_stack *)(*stack)->next->content)->value)
		exec_swap(stack,1);
}

void	sort(t_list *stack_a, t_list *stack_b)
{
	while (ft_lstsize(stack_a)> 3)
		exec_push(&stack_a, &stack_b,2);
	if(ft_lstsize(stack_a) == 3)
		sort_3(&stack_a);
	else if(ft_lstsize(stack_a) == 2)
		sort_2(&stack_a);
	
	weight(stack_a, stack_b);
	show(stack_a, stack_b);
}

