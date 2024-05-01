/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:57:45 by alerome2          #+#    #+#             */
/*   Updated: 2024/05/01 17:22:20 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, unsigned long n)
{
	size_t			i;
	unsigned char	*aux;

	aux = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (aux[i] == (unsigned char)c)
			return (&aux[i]);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
int main (void)
{
	const char *s = "bonjour";
	printf("%s\n",ft_memchr(s,'o',4));
	return 0;
}
*/
