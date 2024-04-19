/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:39:51 by alerome2          #+#    #+#             */
/*   Updated: 2024/04/19 15:08:23 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t size)
{
	size_t	i;
	size_t	s2_len;

	s2_len = ft_strlen(little);
	i = s2_len;
	if (little[0] == '\0' || little == big)
		return ((char *)big);
	while (*big && i <= size)
	{
		if (!ft_strncmp(big, little, s2_len))
			return ((char *)big);
		big++;
		i++;
	}
	return ((void *)0);
}
