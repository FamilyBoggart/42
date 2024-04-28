/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 11:20:52 by alerome2          #+#    #+#             */
/*   Updated: 2024/04/28 17:37:49 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int	word_counter(const char	*s, char c)
{
	int	i;
	int	counter;

	counter = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i] != '\0')
		{
			counter++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		while (s[i] == c && s[i] != '\0')
			i++;
	}
	return (counter);
}

char	**fill_array(char **array, const char *s, char c)
{
	char	*aux_string;
	int		position;
	int		s_size;
	int		array_position;

	array_position = 0;
	position = 0;
	while (s[position] != '\0')
	{
		s_size = 0;
		while (s[position] == c && s[position] != '\0')
			position++;
		while (s[position + s_size] != c && s[position + s_size] != '\0')
			s_size++;
		if (s_size != 0)
		{
			aux_string = (char *)malloc(s_size + 1);
			if (!aux_string)
				return (NULL);
			aux_string = ft_substr(s, position, s_size);
			array[array_position++] = aux_string;
		}
		position = position + s_size;
	}
	return (array);
}

char	**ft_split(const char *s, char c)
{
	char	**array;
	int		array_pos;
	int		position;
	int		words;

	words = word_counter(s, c);
	array_pos = 0;
	position = 0;
	array = (char **)malloc(words + 1);
	if (!array || !s)
		return (NULL);
	array = fill_array(array, s, c);
	array[words] = (void *)0;
	return (array);
}
/*
int main ()
{
	const char *frase= "_Hola_Mundo_";
	char	**array=ft_split(frase,'_');
	int i = 0;
	printf("\nDesde fuera de split\n");
	while (array[i] != (void *)'\0')
	{
		printf("%d: %s\n",i,array[i]);
		i++;
	}
	return 0;
}
*/
