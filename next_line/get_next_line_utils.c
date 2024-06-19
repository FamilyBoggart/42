/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:56:52 by alerome2          #+#    #+#             */
/*   Updated: 2024/05/29 18:54:47 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, unsigned int n)
{
	char			*aux_src;
	char			*aux_dest;
	unsigned int	i;

	aux_src = (char *)src;
	aux_dest = (char *)dest;
	i = 0;
	if (!dest && !src && n != 0)
		return (aux_dest);
	while (i < n)
	{
		aux_dest[i] = aux_src[i];
		i++;
	}
	return (aux_dest);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	else
		return ((void *)0);
}

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
