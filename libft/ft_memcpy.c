/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:11:55 by alerome2          #+#    #+#             */
/*   Updated: 2024/05/14 20:11:35 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, unsigned int n)
{
	char			*aux_src;
	char			*aux_dest;
	unsigned int	i;

	aux_src = (char *)src;
	aux_dest = (char *)dest;
	i = 0;
	if (!dest && !src && n != 0)
		return (aux_dest);
	while (i < n)
	{
		aux_dest[i] = aux_src[i];
		i++;
	}
	return (aux_dest);
}
