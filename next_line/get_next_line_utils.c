/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:56:52 by alerome2          #+#    #+#             */
/*   Updated: 2024/07/11 15:34:06 by alerome2         ###   ########.fr       */
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

char	*ft_strchr(const char *s, int c)
{
	if(!s)
		return (NULL);
	while (*s != '\0' && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return ((void *)0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*aux;
	int		i;
	int		j;

	i = 0;
	if (!s1)
	{
		s1 = malloc(sizeof (char));
		s1[0] = 0;
	}
	if (!s1 || !s2)
		return (NULL);
	aux = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!aux)
		return (NULL);
	j = 0;
	while (s1[j])
		aux[i++] = s1[j++];
	j = 0;
	while (s2[j])
		aux[i++] = s2[j++];
	aux[ft_strlen(s1) + ft_strlen(s2)] = 0;
	free(s1);
	return (aux);
}
