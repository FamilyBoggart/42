/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 11:27:19 by alerome2          #+#    #+#             */
/*   Updated: 2024/07/22 12:20:02 by alerome2         ###   ########.fr       */
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

void	push_swap(int *numbers, int len)
{
	int	i;

	i = 0;
	ft_printf("--SWAP--\n");
	swap(numbers, len);
	while (i < len)
		ft_printf("%d\n", numbers[i++]);
	ft_printf("--ROTATE--\n");
	rotate(numbers, len);
	i = 0;
	while (i < len)
		ft_printf("%d\n", numbers[i++]);
}

int	push(void)
{
	return (0);
}
