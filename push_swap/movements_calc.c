/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_calc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:34:33 by alerome2          #+#    #+#             */
/*   Updated: 2024/09/11 11:43:17 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*up_down_b(t_list *stack_b, int pos)
{
	t_list	*temp;
	int		*moves_b;
	int		cont;

	cont = 0;
	temp = stack_b;
	moves_b = ((t_stack *)temp->content)->moves;
	while (temp)
	{
		if (((t_stack *)temp->content)->pos == pos)
			break;
		cont++;
		temp = temp->next;
	}
	if (cont >= (ft_lstsize(stack_b) / 2) + 1)
		moves_b[2] =(ft_lstsize(stack_b) / 2) + 1 - cont + 1; //Hacia abajo
	else
	{
		moves_b[2]=cont;
		moves_b[3]=1;
	}
	return (moves_b);
}
void up_down_a(t_list *stack, int cont, t_list **temp)
{
    int size;

    size = ft_lstsize(stack);
    if (cont >= (size / 2) + 1)
    {
        ((t_stack *)(*temp)->content)->moves[0] = (size / 2) + 1 - cont + 1; //Hacia abajo
        ((t_stack *)(*temp)->content)->moves[1] = 2;
    }       
    else
    {
        ((t_stack *)(*temp)->content)->moves[0] = cont;
        ((t_stack *)(*temp)->content)->moves[1] = 1; 
    }
}

void count_movements(t_list *stack_a,t_list **t, int next)
{
	t_list	*temp;
	int		cont;

	cont = 0;
	temp = stack_a;
	while(temp)
	{
		if (((t_stack *)temp->content)->pos == next)
		{
			up_down_a(stack_a, cont, t);
			break;
		}
		cont++;
		temp = temp->next;
	}
}

void set_default_moves(t_list *stack)
{
	t_list	*temp;

	temp = stack;
	while (temp)
	{
		((t_stack *)temp->content)->moves = calloc(4, sizeof(int));
		temp = temp->next;
	}
}
void weight(t_list *stack_a, t_list *stack_b)
{
	int		actualpos;
	int		nextpos;
	int 	size;
	t_list	*temp;

	temp = stack_b;
	set_default_moves(stack_a);
	set_default_moves(stack_b);
	ft_printf("Pre movement\n");
	show(stack_a, stack_b);
	ft_printf("\nPost movement\n");
	size = ft_lstsize(stack_a) + ft_lstsize(stack_b);
	while (temp)
	{
		actualpos = ((t_stack *)temp->content)->pos;
		nextpos = find_next_pos(stack_a, actualpos, size);
		ft_printf("pos: %d nextpos: %d\n", actualpos, nextpos);
		count_movements(stack_a, &temp, nextpos);
		temp = temp->next;
	}
}