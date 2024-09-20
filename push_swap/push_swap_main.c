/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@sutdent.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:49:23 by alerome2          #+#    #+#             */
/*   Updated: 2024/09/20 12:58:04 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int	*array;
	int	aux;
	t_list	*stack_a;

	aux = 0;
	if (argc == 1)
		return (0);
	array = check(argv + 1, &argc, &aux);
	if(!array)
	{
		free(array);
		ft_printf("Error\n");
		return (0);
	}
	if (aux == 0)
		stack_a = create_stack(array, argc - 1);
	else
		stack_a = create_stack(array, argc);
	find_pos(stack_a);
	set_default_moves(stack_a);
	sort(stack_a);
	free_stack(stack_a);
	free(array);
		
}
