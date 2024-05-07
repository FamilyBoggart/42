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
#include <stdio.h>

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*aux;
	int	len;

	i = 0;
	while(*s1 && ft_strchr(set,*s1))
		s1++;
	len = ft_strlen(s1);
	printf("Longitud: %d",len);
	aux = ft_substr	
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
