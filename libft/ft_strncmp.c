/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:52:37 by alerome2          #+#    #+#             */
/*   Updated: 2024/05/14 20:13:40 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	i;
	unsigned char	*aux1;
	unsigned char	*aux2;

	aux1 = (unsigned char *)s1;
	aux2 = (unsigned char *)s2;
	i = 0;
	while ((aux1[i] || aux2[i]) && i < n)
	{
		if (aux1[i] > aux2[i])
			return (1);
		if (aux1[i] < aux2[i])
			return (-1);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
int main (void)
{
	char *s1 = "\200";
	char *s2 = "\0";
	printf("%d",ft_strncmp(s1,s2,1));
	return 0;
}
*/
