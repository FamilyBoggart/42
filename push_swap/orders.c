/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 11:27:19 by alerome2          #+#    #+#             */
/*   Updated: 2024/09/09 11:28:31 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *stack)
{
	t_stack	*aux;

	aux = (t_stack *)(stack->content);
	stack->content = stack->next->content;
	stack->next->content = aux;
}

void	rotate(t_list **stack)
{
	t_list	*last;
	t_list	*aux;
	
	last = ft_lstlast(*stack);
	aux = *stack;
	while(aux->next != last)
		aux = aux->next;
	last->next = *stack;
	aux->next = NULL;
	if(!aux->next)
	*stack = last;
}

void	rev_rotate(t_list **stack)
{
	t_list	*first;
	t_list	*aux;
	
	aux = *stack;
	first = (*stack)->next;
	*stack = ft_lstlast(*stack);
	(*stack)->next = aux;
	(*stack)->next->next = NULL;
	*stack = first;
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*aux;

	if (!*stack_a)
		return;
	aux = *stack_a;
	*stack_a = (*stack_a)->next;
	ft_lstadd_front(stack_b, aux);
}

void	push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*aux;

	if (!*stack_b)
		return;
	aux = *stack_b;
	*stack_b = (*stack_b)->next;
	ft_lstadd_front(stack_a, aux);
}
