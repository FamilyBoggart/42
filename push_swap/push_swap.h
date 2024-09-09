/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 11:28:33 by alerome2          #+#    #+#             */
/*   Updated: 2024/09/09 11:29:09 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./libft/inc/libft/libft.h"
#include "./libft/inc/printf/ft_printf.h"
#include "./libft/inc/get_next_line/get_next_line.h"

typedef struct s_stack
{
	int					value;
}	t_stack;

void	sort(t_list *stack_a, t_list *stack_b);
int		checker(int *numbers);
void	swap(t_list *stack);
void	push_b(t_list **stack_a, t_list **stack_b);
void	push_a(t_list **stack_a, t_list **stack_b);
void	rotate(t_list **stack);
void	rev_rotate(t_list **stack);
int		array_len(int *stack);
