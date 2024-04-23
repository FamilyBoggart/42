/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:12:32 by alerome2          #+#    #+#             */
/*   Updated: 2024/04/23 11:51:18 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*sub_str;
	size_t			i;
	size_t			j;

	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	if ((int)start > ft_strlen(s))
		sub_str = malloc (1);
	else
		sub_str = malloc(sizeof(char) * (len + 1));
	if (!s || start < 0 || !sub_str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (i >= start && i < (len + start) && s[i] != '\0')
			sub_str[j++] = s[i];
		i++;
	}
	sub_str[j] = '\0';
	return (sub_str);
}
/*
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
	return 0;
}
*/
