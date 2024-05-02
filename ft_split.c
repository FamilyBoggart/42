/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 22:58:16 by alerome2          #+#    #+#             */
/*   Updated: 2024/05/02 12:59:48 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

typedef struct s_counter
{
	int	i;
	int	j;
	int	k;
	int	len;
	int	size;
}t_counter;

int	word_counter(char	*s, char c)
{
	int	cont;
	int	i;

	i = 0;
	cont = 0;
	if (s[0] != c && s[0] != '\0')
		cont++;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			cont++;
		i++;
	}
	return (cont);
}

char	*fill_array(char *s, int *s_counter, char c)
{
	int 	cont;
	char	*word;
	int		i;
	int		aux;

	aux = *s_counter;
	cont = 0;
	i = 0;
	while (s[aux] != c && s[aux] != '\0')
	{
		cont++;
		aux++;
	}
	word = (char *)malloc(cont + 1);
	if(!word)
	{
		free(word);
		return (NULL);
	}
	aux = *s_counter;
	while (i < cont)
		word[i++] = s[aux++];
	word[i] = '\0';
	*s_counter = aux;
	return (word); 
}

char	**ft_split(const char	*s, char c)
{
	char		**array;
	t_counter	counter;

	counter.k = 0;
	counter.size = word_counter((char *)s, c);
	array = (char **)malloc(counter.size + 1);
	if (!array)
		return ((void *)0);
	while (counter.i < counter.size)
	{
		counter.j = 0;
		while (s[counter.k] == c && s[counter.k] != '\0')
			counter.k++;
		if (s[counter.k] != c && s[counter.k] != '\0')
		{
			array[counter.i] = fill_array((char *)s, &counter.k, c);
			if(!array[counter.i])
			{
				free(array[counter.i]);
				free(array);
				return ((void *)0);
			}
		}
		counter.i++;
	}
	array[counter.size] = (void *)0;
	return (array);
}
/*
#include <stdio.h>
int main ()
{
//	char 	*s1 = "";
//	char	*s2 = "HOla";
	char	*s3 = "Hola_mundo";
//	char	*s4 = "_Hola_mundo";
//	char	*s5 = "_Hola_mundo_";
//	char	*s6 = "____Hola__Mundo____";

//	printf("Palabras : %d\n",word_counter(s1,'_'));
//	printf("Palabras : %d\n",word_counter(s2,'_'));
	printf("Palabras : %d\n",word_counter(s3,'_'));
//	printf("Palabras : %d\n",word_counter(s4,'_'));
//   printf("Palabras : %d\n",word_counter(s5,'_'));
//   printf("Palabras : %d\n",word_counter(s6,'_'));

	printf("------ FT_SPLIT------\n");
	char **array = ft_split(s3,'_');
	printf("%s\n",array[0]);
	return (0);
}
*/
