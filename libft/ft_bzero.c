/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:17:50 by alerome2          #+#    #+#             */
/*   Updated: 2024/04/15 18:05:26 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, unsigned long n)
{
	char	*pointer;

	pointer = ft_memset(s, 0, n);
	return (pointer);
}
/*
#include <stdio.h>
#include <strings.h>
int main(void)
{
	char p1[] = "Hola mundo";
	printf(ft_bzero(p1, 7));
	return 0;
}
*/
