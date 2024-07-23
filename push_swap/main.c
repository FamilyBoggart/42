/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 11:31:29 by alerome2          #+#    #+#             */
/*   Updated: 2024/07/23 21:00:22 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// BUCLE (ARRAY NO ORDENADO)
// 1. Calculas tamaño de array
// 2. Encuentras la posicion del valor minimo
// 3. Calculas el camino mas corto para moverlo a la posicion 0
// 4. Mueves el minimo al stack_b
// FIN BUCLE (ARRAY NO EXISTENTE)
// 5. Movemos todos los valores de stack b a stack a
#include "push_swap.h"

int	array_len(int *stack)
{
	int	len;

	len = 0;
	while (stack[len])
		len++;
	return (len - 1);
}

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

int	sort_alg(int *stack)
{
	int	len;
	int	start;
	int	*stack_a;
	int	*stack_b;
	int	distance;

	distance = 0;
	stack_a = stack;
	stack_b = (void *)0;
	if (!checker(stack))
	{
		len = array_len(stack_a);
		start = find_min(stack_a);
		if (start == 0)
			distance += push(stack_a, stack_b, 0);
		else if (start == 1)
			distance += swap(stack_a, len);
		else if (start <= (len / 2) + 1)
			distance += rotate(stack_a, len);
		else
			distance += rev_rotate(stack_a, len);
	}
	push(stack_a, stack_b, 1);
	return (distance);
}

int	main(int argc, char *argv[])
{
	int	*array;
	int	i;
	int	movements;

	movements = 0;
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
	movements += sort_alg(array);
	ft_printf("El array se ha movido %d movimientos", movements);
	return (movements);
}
