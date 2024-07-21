/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 11:27:19 by alerome2          #+#    #+#             */
/*   Updated: 2024/07/21 14:25:21 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//PSEUDOCODE
// 1. NECESITAMOS PASAR UNA LISTA DE ARGUMENTOS DADOS A UNA LISTA ENLAZADA
// 2. CADA NODO DE LA LISTA CONTIENE UN VALOR Y UN PUNTERO A LOS NODOS ADYACENTES
// 3. LOS NODOS TOP Y BOTTOM SE APUNTARÁN CIRCULARMENTE
// 4. EL ATRIBUTO IS_TOP Y IS_BOTTOM SE USAN PARA INDICAR QUE SON TOP Y BOTTOM
#include "push_swap.h"

int	swap(int *stack, int len)
{
	int	aux;

	aux = 0;
	if (len >= 2)
	{
		aux = stack[0];
		*stack = stack[1];
		stack++;
		*stack = aux;
		return (1);
	}
	return (aux);
}

void	push_swap(int *numbers, int len)
{
	swap(numbers, len);
	while (*numbers)
		ft_printf("%d\n", *numbers++);
	ft_printf("-\na\n\n");
}

int	push(void)
{
	return (0);
}

int	rotate(void)
{
	return (0);
}
