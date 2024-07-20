/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:35:31 by alerome2          #+#    #+#             */
/*   Updated: 2024/07/18 20:07:31 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft/libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*aux;
	int		size;
	int		i;
	int		j;

	i = 0;
	j = 0;
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	aux = (char *)malloc(size);
	if (!aux)
		return (NULL);
	while (s1[i] != '\0')
	{
		aux[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		aux[i + j] = s2[j];
		j++;
	}
	aux[i + j] = '\0';
	return (aux);
}
/*
int main (void)
{
	const char *s1 = "Hola";
	const char *s2 = " Mundo";
	printf("%s",ft_strjoin(s1,s2));
	return 0;
}
*/
