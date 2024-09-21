/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_instructions_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:30:51 by alerome2          #+#    #+#             */
/*   Updated: 2024/09/21 12:28:37 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	read_push(t_list **stack_a, t_list **stack_b, char *inst)
{
	if (!ft_strncmp(inst, "pa\n", 3))
		push_a(stack_a, stack_b);
	else
		push_b(stack_a, stack_b);
}

void	read_swap(t_list **stack_a, t_list **stack_b, char *inst)
{
	if (!ft_strncmp(inst, "sa\n", 3))
		swap(stack_a);
	else if (ft_strncmp(inst, "sb\n", 3))
		swap(stack_b);
	else
	{
		swap(stack_a);
		swap(stack_b);
	}
}

void	read_rev_rotate(t_list **stack_a, t_list **stack_b, char *inst)
{
	if (!ft_strncmp(inst, "rra", 3))
		rotate(stack_a);
	else if (!ft_strncmp(inst, "rrb", 3))
		rotate(stack_b);
	else
	{
		rotate(stack_a);
		rotate(stack_b);
	}
}

void	read_rotate(t_list **stack_a, t_list **stack_b, char *inst)
{
	if (!ft_strncmp(inst, "ra\n", 3))
		rev_rotate(stack_a);
	else if (!ft_strncmp(inst, "rb\n", 3))
		rev_rotate(stack_b);
	else if (!ft_strncmp(inst, "rr\n", 3))
	{
		rev_rotate(stack_a);
		rev_rotate(stack_b);
	}
}

void	read_instructions(t_list **stack_a, t_list **stack_b, char *inst)
{
	if (!ft_strncmp(inst, "pa\n", 3) || !ft_strncmp(inst, "pb\n", 3))
		read_push(stack_a, stack_b, inst);
	else if (!ft_strncmp(inst, "sa\n", 3) || !ft_strncmp(inst, "sb\n", 3))
		read_swap(stack_a, stack_b, inst);
	else if (!ft_strncmp(inst, "ss\n", 3))
		read_swap(stack_a, stack_b, inst);
	else if (!ft_strncmp(inst, "ra\n", 3) || !ft_strncmp(inst, "rb\n", 3))
		read_rotate(stack_a, stack_b, inst);
	else if (!ft_strncmp(inst, "rr\n", 3))
		read_rotate(stack_a, stack_b, inst);
	else if (!ft_strncmp(inst, "rra\n", 4) || ft_strncmp(inst, "rrb\n", 4))
		read_rev_rotate(stack_a, stack_b, inst);
	else if (!ft_strncmp(inst, "rrr\n", 4))
		read_rev_rotate(stack_a, stack_b, inst);
}
