/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:15:20 by alerome2          #+#    #+#             */
/*   Updated: 2024/05/14 20:13:57 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char	*set)
{
	char	*s_aux;
	int		len;

	if (!s1 || !set)
		return (NULL);
	while (*s1 != '\0' && ft_strchr(set,*s1))
		s1++;
	len = ft_strlen(s1);
	while (len > 0 && ft_strchr(set, s1[len]))
		len--;
	s_aux = ft_substr((char *)s1, 0, len + 1);
	return (s_aux);
}
/*
int main (void)
{
	char	*s1 = "     Hola   Mundo";
	char	*set = " ";
	ft_strtrim(s1,set);
}
*/
