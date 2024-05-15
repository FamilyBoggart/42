/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 06:26:56 by alerome2          #+#    #+#             */
/*   Updated: 2024/05/14 20:11:43 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, unsigned int n)
{
	char			*aux_src;
	char			*aux_dest;
	unsigned int	i;

	aux_src = (char *) src;
	aux_dest = dest;
	i = 0;
	if (!dest && !src && n > 0)
		return (dest);
	if (src < dest)
	{
		while (n-- > 0)
			aux_dest[n] = aux_src[n];
	}
	else
	{
		while (i < n)
		{
			aux_dest[i] = aux_src[i];
			i++;
		}
	}
	return (aux_dest);
}
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	char origen[7] = "ABCDEF";
	char destino[100] = "DEH";

	printf("Antes de memmove: %s",destino);
	memmove(destino,origen,sizeof(origen));
	printf("Despues de memmove: %s", destino);
	return (0);
}
*/
