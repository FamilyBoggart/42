/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:49:23 by alerome2          #+#    #+#             */
/*   Updated: 2024/10/05 13:26:48 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*first_value(t_list *stack_a, int min_value)
{
	t_list	*temp;

	temp = stack_a;
	while (temp)
	{
		if (((t_stack *)temp->content)->value == min_value)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

int	main(int argc, char *argv[])
{
	int		*array;
	t_list	*first;
	int		aux;
	t_list	*stack_a;

	stack_a = NULL;
	aux = 0;
	if (argc == 1)
		return (0);
	array = check(argv + 1, &argc, &aux);
	if (!array)
	{
		ft_printf("Error\n");
		return (0);
	}
	if (aux == 0)
		stack_a = create_stack(array, argc - 1);
	else
		stack_a = create_stack(array, argc);
	find_pos(stack_a);
	first = first_value(stack_a, find_min(stack_a, MIN_INT, "value"));
	set_default_moves(stack_a);
	sort(stack_a);
	free_stack(first);
	free(array);
}
