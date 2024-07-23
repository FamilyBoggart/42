/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 11:31:29 by alerome2          #+#    #+#             */
/*   Updated: 2024/07/23 20:03:23 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stacks(int *numbers, int init_len)
{
	int	*stack_a;

	stack_a = ft_calloc(1, init_len);
	stack_a = numbers;
	while (*stack_a)
		ft_printf("%d\n", *stack_a++);
}

int	find_min(int *stack)
{
	int	min;
	int	i;
	int	start;

	i = 0;
	min = 2147483647;
	while (*stack)
	{
		if (*stack < min)
		{
			min = *stack;
			start = i;
		}
		stack++;
		i++;
	}
	ft_printf("min number: %d\nPosition: %d\n", min, start);
	return (start);
}

void	sort_alg(int *stack, int len)
{
	int	start;
	int	*stack_a;
	int	distance;

	stack_a = stack;
	start = find_min(stack_a);
	if (len - start >= start)
		distance = start;
	else
		distance = len - start;
	ft_printf("Distacia hasta extremo : %d", distance);
}

int	main(int argc, char *argv[])
{
	int	*array;
	int	i;

	i = 1;
	array = malloc(argc * sizeof(int));
	if (argc < 2 || !array)
	{
		ft_printf("Error");
		return (0);
	}
	while (argv[i])
	{
		array[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	array[i - 1] = '\0';
	if (checker(array))
		ft_printf("El array esta ordenado");
	else
		ft_printf("El array no esta ordenado");
	return (0);
}
