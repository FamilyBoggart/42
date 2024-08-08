/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 11:28:33 by alerome2          #+#    #+#             */
/*   Updated: 2024/08/08 13:24:37 by alerome2         ###   ########.fr       */
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

int		checker(int *numbers);
int		swap(int *stack, int len);
int		push(int *stack_a, int *stack_b, int option);
int		rotate(int *stack, int len);
int		rev_rotate(int *stack, int len);
int		array_len(int *stack);
