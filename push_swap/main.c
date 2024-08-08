/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 11:31:29 by alerome2          #+#    #+#             */
/*   Updated: 2024/08/08 16:01:51 by alerome2         ###   ########.fr       */
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

t_list	*create_stack(int *array)
{
	t_list	*stack_a;
	t_list	*wagon;
	t_stack	*pointer;

	stack_a = NULL;
	while(*array)
	{
		t_stack	number;
		wagon = malloc(sizeof(t_list));
		pointer =malloc(sizeof(t_stack));
		if(!wagon || !pointer)
		{
			free(wagon);
			free(pointer);
			free(array);
			return (NULL);
		}
		number.value = *array;
		*pointer = number;
		wagon->content=pointer;
		wagon->next = NULL;
		ft_lstadd_back(&stack_a, wagon);
		array++;
	}
	return (stack_a);
}

/*
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
*/
void show_stack(t_list *stack) 
{
	while(stack)
	{
		ft_printf("%d\n", ((t_stack *)stack->content)->value);
		stack = stack->next;
	}
}

void free_stack(t_list *stack)
{
	t_list	*temp;

	while(stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp->content);
		free(temp);
	}
}
int	main(int argc, char *argv[])
{
	int	*array;
	int	i;
	t_list	*stack_a;
	t_list	*stack_b;
	
	i = 1;
	array = malloc((argc - 1) * sizeof(int));
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
	stack_a =create_stack(array);
	stack_b = NULL;
	show_stack(stack_a);
	ft_printf("\n-\na\n");
	free_stack(stack_a);
	free(array);
}
