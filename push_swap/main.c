/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 11:31:29 by alerome2          #+#    #+#             */
/*   Updated: 2024/07/21 14:58:03 by alerome2         ###   ########.fr       */
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
	push_swap(numbers, init_len);
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
	stacks(array, i - 1);
	return (0);
}
