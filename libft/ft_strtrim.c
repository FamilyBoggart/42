/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:01:26 by alerome2          #+#    #+#             */
/*   Updated: 2024/04/23 14:03:27 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	check_found_char(const char *s1, const char *set, int i)
{
	int	j;
	int	is_char;

	is_char = 0;
	j = 0;
	while (set[j] != '\0')
	{
		if (s1[i] == set[j++])
			is_char = 1;
	}
	if (is_char == 0)
		return (1);
	else
		return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*aux;
	int		is_char;
	int		i;
	int		o;

	i = 0;
	o = 0;
	is_char = 0;
	if (ft_strlen(set) == 0)
		return ((char *)s1);
	if (ft_strlen(s1) == 0)
		return ((char *)set);
	aux = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	while (s1[i] != '\0')
	{
		if (check_found_char(s1, set, i))
			aux[o++] = s1[i];
		i++;
	}
	aux[i] = '\0';
	return (aux);
}
/*
#include <stdio.h>
int main(void)
{
	char	*s1 = "Hola mundo";
	char 	*remover = "om";
	printf("%s",ft_strtrim(s1,remover));
	return 0;
}
*/
