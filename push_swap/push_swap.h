/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 11:28:33 by alerome2          #+#    #+#             */
/*   Updated: 2024/09/11 13:49:42 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./libft/inc/libft/libft.h"
#include "./libft/inc/printf/ft_printf.h"
#include "./libft/inc/get_next_line/get_next_line.h"

#define MAX_INT 2147483647
#define MIN_INT -2147483648

typedef struct s_stack
{
	int					value;
	int					weight;
	int					pos;
	int					*moves;
}	t_stack;

int		find_min(t_list *stack, int prev_min, char *type);
void	show(t_list *stack_a, t_list *stack_b);
void	sort(t_list *stack_a, t_list *stack_b);
int		checker(int *numbers);
void	swap(t_list **stack);
void	push_b(t_list **stack_a, t_list **stack_b);
void	push_a(t_list **stack_a, t_list **stack_b);
void	rotate(t_list **stack);
void	rev_rotate(t_list **stack);
int		array_len(int *stack);
// Positions
void	find_pos(t_list *stack);
int		find_next_pos(t_list *stack, int pos, int size);
void 	show_pos(t_list *stack);
// Weight
void 	weight(t_list *stack_a, t_list *stack_b);
void	push_from_b(t_list **stack_a, t_list **stack_b,t_list *t);
//Instructions
void	exec_swap(t_list **stack, int option);
void	exec_push(t_list **stack_a, t_list **stack_b, int option);
void	exec_rotate(t_list **stack_a,t_list **stack_b, int option);
void	exec_rev_rotate(t_list **stack_a, t_list **stack_b, int option);
