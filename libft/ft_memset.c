/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:40:02 by alerome2          #+#    #+#             */
/*   Updated: 2024/05/14 20:14:43 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, unsigned long n)
{
	unsigned long		i;
	char				*pointer;

	pointer = s;
	i = 0;
	while (i < n)
	{
		pointer[i] = c;
		i++;
	}
	return (pointer);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char p1[] = "Hola mundo";
	printf(memset(p1, '3',7));
	printf("\n");
	printf(ft_memset(p1,'i',4));
	return 0;
}
*/
