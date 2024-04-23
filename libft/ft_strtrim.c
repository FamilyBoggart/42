/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:01:26 by alerome2          #+#    #+#             */
/*   Updated: 2024/04/23 14:55:53 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(const char *s1, const char *set)
{
	int		i;
	int		set_len_counter;
	char	*aux;

	aux = (char *)malloc(ft_strlen((char *)set);
	i = 0;
	set_len_counter = ft_strlen(set);
	while (s[i] != '\0')
	{
		while(set_len_counter > 0;
		if (!ft_strchr(s1,set[i]))
			
		else
		{
			
			counter++

		}
	}
	return (aux);
}

#include <stdio.h>
int main(void)
{
	char	*s1 = "Hola mundo";
	char 	*remover = "om";
	printf("%s",ft_strtrim(s1,remover));
	return 0;
}

