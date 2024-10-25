/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:12:32 by alerome2          #+#    #+#             */
/*   Updated: 2024/07/18 20:07:31 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft/libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*aux;
	size_t	i;
	size_t	slen;

	i = 0;
	slen = ft_strlen(s);
	if (start >= slen)
	{
		aux = malloc(1);
		if (!aux)
			return (NULL);
		aux[0] = '\0';
		return (aux);
	}
	if (len > (size_t)ft_strlen(&s[start]))
		len = ft_strlen(&s[start]);
	aux = malloc(len + 1);
	if (!aux)
		return (NULL);
	while (i < len && s[start] != '\0')
		aux[i++] = s[start++];
	aux[i] = '\0';
	return (aux);
}
/*
#include <stdio.h>
int main (void)
{
	char	*s1 = ""; // 0 
	char	*s2 = "Hola mundo"; //10 
	char 	*s3 = "Esto son 23 caracteres";//23 

	// OPCION 1: Cadena vacia
	printf("1: %s\n", ft_substr(s1,0,10));
	// OPCION 2: Cadena vacia y start != 0
	printf("2: %s\n", ft_substr(s1,0,10));
	// OPCION 3: Cadena con start = 0, len < sizeof(s)
	printf("3: %s\n", ft_substr(s3,0,7));
	// OPCION 4: Longitud mayor a strlen
	printf("4: %s\n", ft_substr(s2,0,15));
	// SPLIT
	printf("split: %s\n", ft_substr("_Hola_Mundo_",1,4));
	return 0;
}
*/
