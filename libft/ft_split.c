/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:01:10 by alerome2          #+#    #+#             */
/*   Updated: 2024/05/02 15:56:25 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
typedef struct s_counter
{
    int i;
    int j;
    int k;
    int len;
    int size;
}t_counter;
int word_counter(char   *s, char c)
{
    int cont;
    int i;

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

char    *fill_array(char *s, int *s_counter, char c)
{
    int     cont;
    char    *word;
    int     i;
    int     aux;

    aux = *s_counter;
    cont = 0;
    i = 0;
    while (s[aux] != c && s[aux] != '\0')
    {
        cont++;
        aux++;
    }
    word = (char *)malloc((cont + 1) * sizeof(char));
    if(!word)
        return (NULL);
    aux = *s_counter;
    while (i < cont)
        word[i++] = s[aux++];
    word[i] = '\0';
    *s_counter = aux;
    return (word);
}

void free_array(char **array, int size)
{
	int	i;

	i = 0;
	while (i <= size)
	{
		array[i] = NULL;
		free(array[i]);
		i++;
	}
	free(array);
}

char    **ft_split(const char   *s, char c)
{
    char        **array;
    t_counter   counter;

    counter.k = 0;
    counter.size = word_counter((char *)s, c);
    array = (char **)malloc((counter.size + 1) * sizeof(char *));
    if (!array || !s)
        return ((void *)0);
    while (counter.i < counter.size && s)
    {
        counter.j = 0;
        while (s[counter.k] == c && s[counter.k] != '\0')
            counter.k++;
        if (s[counter.k] != c && s[counter.k] != '\0')
        {
            array[counter.i] = fill_array((char *)s, &counter.k, c);
            if(!array[counter.i])
            {
				free_array(array, counter.size);
                return ((void *)0);
            }
        }
        counter.i++;
    }
    array[counter.size] = (void *)0;
    return (array);
}
/*
int main ()
{
//  char    *s1 = "";
//  char    *s2 = "HOla";
//  char    *s3 = "Hola_mundo";
//  char    *s4 = "_Hola_mundo";
//  char    *s5 = "_Hola_mundo_";
//  char    *s6 = "____Hola__Mundo____";
//	char	*s7 = "________";
//  printf("Palabras : %d\n",word_counter(s1,'_'));
//  printf("Palabras : %d\n",word_counter(s2,'_'));
//    printf("Palabras : %d\n",word_counter(s3,'_'));
//  printf("Palabras : %d\n",word_counter(s4,'_'));
//   printf("Palabras : %d\n",word_counter(s5,'_'));
//   printf("Palabras : %d\n",word_counter(s6,'_'));
//	printf("Palabras : %d\n",word_counter(s7,'_'));

    printf("------ FT_SPLIT------\n");
    char **array = ft_split("hello!",32:' ');
    printf("%s\n",array[0]);
	printf("%s\n",array[1]);
	printf("%s\n",array[2]);
    return (0);
}
*/
