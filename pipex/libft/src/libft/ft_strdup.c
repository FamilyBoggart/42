/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:11:22 by alerome2          #+#    #+#             */
/*   Updated: 2024/07/18 20:07:31 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft/libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char		*aux;
	int			s1_size;
	int			i;

	i = 0;
	s1_size = ft_strlen(s1) + 1;
	aux = (char *) malloc(s1_size);
	if (!aux)
		return (NULL);
	while (s1[i] != '\0')
	{
		aux[i] = ((char *)s1)[i];
		i++;
	}
	aux[i] = '\0';
	return (aux);
}
