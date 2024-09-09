/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_alg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:08:11 by alerome2          #+#    #+#             */
/*   Updated: 2024/09/09 13:10:43 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void show(t_list *stack)
{
	while (stack)
	{
		ft_printf("%d", ((t_stack *)stack->content)->value);
		stack = stack->next;
	}
}

void sort_3(t_list **stack)
{
	int	s1;
	int	s2;
	int	s3;

	s1 = ((t_stack *)(*stack)->content)->value;
	s2 = ((t_stack *)(*stack)->next->content)->value;
	s3 = ((t_stack *)(*stack)->next->next->content)->value;	
	if (s1 < s2 && s2 > s3 && s1 < s3)
	{
		swap(stack);
		rev_rotate(stack);
	}
	else if (s1 > s2 && s2 < s3 && s1 < s3)
		swap(stack);
	else if (s1 > s2 && s2 < s3 && s1 > s3)
		rev_rotate(stack);
	else if (s1 < s2 && s2 > s3 && s1 > s3)
	{
		rotate(stack);
		ft_printf("ra\n");
	}
	else if (s1 > s2 && s2 > s3)
	{
		swap(stack);
		rotate(stack);
	}
}

void	sort_2(t_list **stack)
{
	if (((t_stack *)(*stack)->content)->value > ((t_stack *)(*stack)->next->content)->value)
		swap(stack);
}

void	sort(t_list *stack_a, t_list *stack_b)
{
	while (ft_lstsize(stack_a)> 3)
		push_b(&stack_a, &stack_b);
	if(ft_lstsize(stack_a) == 3)
		sort_3(&stack_a);
	else if(ft_lstsize(stack_a) == 2)
		sort_2(&stack_a);
	ft_printf("stack_a\n");
	show(stack_a);
	ft_printf("\nstack_b\n");
	show(stack_b);
}

