/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_alg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:08:11 by alerome2          #+#    #+#             */
/*   Updated: 2024/09/11 13:57:37 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_list **stack_a, t_list **stack_b)
{
	int	s1;
	int	s2;
	int	s3;

	s1 = ((t_stack *)(*stack_a)->content)->value;
	s2 = ((t_stack *)(*stack_a)->next->content)->value;
	s3 = ((t_stack *)(*stack_a)->next->next->content)->value;
	if (s1 < s2 && s2 > s3 && s1 < s3)
	{
		exec_swap(stack_a,1);
		exec_rev_rotate(stack_a,stack_b,1);
	}
	else if (s1 > s2 && s2 < s3 && s1 < s3)
		exec_swap(stack_a,1);
	else if (s1 > s2 && s2 < s3 && s1 > s3)
		exec_rev_rotate(stack_a,stack_b,1);
	else if (s1 < s2 && s2 > s3 && s1 > s3)
		exec_rotate(stack_a,stack_b,1);
	else if (s1 > s2 && s2 > s3)
	{
		exec_swap(stack_a,1);
		exec_rotate(stack_a,stack_b,1);
	}
}

void	sort_2(t_list **stack)
{
	if (((t_stack *)(*stack)->content)->value > ((t_stack *)(*stack)->next->content)->value)
		exec_swap(stack,1);
}

t_list	*execute(t_list *stack_b)
{
	t_list	*temp;
	int		min_weight;

	min_weight = MAX_INT;
	temp = stack_b;
	while (temp)
	{
		if (((t_stack *)temp->content)->weight < min_weight)
			min_weight = ((t_stack *)temp->content)->weight;
		temp = temp->next;
	}
	temp = stack_b;
	while (temp)
	{
		if (((t_stack *)temp->content)->weight == min_weight)
		{
			ft_printf("pushing %d\n", ((t_stack *)temp->content)->value);
			break ;
		}
		temp = temp->next;
	}	
	return (temp);
}

void	sort(t_list *stack_a, t_list *stack_b)
{
	while (ft_lstsize(stack_a)> 3)
		exec_push(&stack_a, &stack_b,1);
	if(ft_lstsize(stack_a) == 3)
		sort_3(&stack_a, &stack_b);
	else if(ft_lstsize(stack_a) == 2)
		sort_2(&stack_a);
	
	weight(stack_a, stack_b);
	show(stack_a, stack_b);
	push_from_b(&stack_a, &stack_b,execute(stack_b));
	show(stack_a, stack_b);
}

