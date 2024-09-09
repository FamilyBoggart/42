/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 11:31:29 by alerome2          #+#    #+#             */
/*   Updated: 2024/09/09 14:20:52 by alerome2         ###   ########.fr       */
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
	t_stack	number;

	stack_a = NULL;
	while (*array)
	{
		wagon = malloc(sizeof(t_list));
		pointer = malloc(sizeof(t_stack));
		if (!wagon || !pointer)
		{
			free(wagon);
			free(pointer);
			free(array);
			return (NULL);
		}
		number.value = *array;
		*pointer = number;
		wagon->content = pointer;
		wagon->next = NULL;
		ft_lstadd_back(&stack_a, wagon);
		array++;
	}
	return (stack_a);
}

void	free_stack(t_list *stack)
{
	t_list	*temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp->content);
		free(temp);
	}
}

int	main(int argc, char *argv[])
{
	int		*array;
	int		i;
	t_list	*stack_a;
	t_list	*stack_b;

	i = 1;
	array = malloc((argc - 1) * sizeof(int));
	if (argc < 2 || !array)
	{
		free(array);
		ft_printf("Error");
		return (0);
	}
	while (argv[i])
	{
		array[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	stack_a = create_stack(array);
	stack_b = NULL;
	
	find_pos(stack_a);
	
	sort(stack_a, stack_b);
	free_stack(stack_a);
	free(array);
}
