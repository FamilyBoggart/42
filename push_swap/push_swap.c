/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 11:27:19 by alerome2          #+#    #+#             */
/*   Updated: 2024/07/23 19:35:48 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(int *stack, int len)
{
	int	aux;

	aux = 0;
	if (len >= 2)
	{
		aux = stack[0];
		*stack = stack[1];
		stack++;
		*stack = aux;
		return (1);
	}
	return (aux);
}

int	rotate(int *stack, int len)
{
	int	last;
	int	aux;

	last = stack[0];
	while (*stack)
		stack++;
	while (len--)
	{
		stack--;
		aux = *stack;
		*stack = last;
		last = aux;
	}
	return (0);
}

int	rev_rotate(int *stack, int len)
{
	int	last;
	int	aux;

	last = stack[len - 1];
	while (len--)
	{
		aux = *stack;
		*stack = last;
		last = aux;
		stack++;
	}
	return (1);
}

int	checker(int *stack)
{
	int	i;

	i = 1;
	while (stack[i])
	{
		if (stack[i] && stack[i] < stack[i - 1])
			return (0);
		i++;
	}
	return (1);
}

int	push(void)
{
	return (0);
}
