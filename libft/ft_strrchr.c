/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:10:00 by alerome2          #+#    #+#             */
/*   Updated: 2024/04/16 14:01:18 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	size_str(char *s)
{
	int	size;

	size = 0;
	while (*s != '\0')
	{
		s++;
		size++;
	}
	return (size);
}

char	*ft_strrchr(char *s, int c)
{
	int	size;

	size = size_str(s);
	while (*s != '\0')
		s++;
	while (size >= 0)
	{
		if (*s == (char)c)
			return (s);
		s--;
		size--;
	}
	return ((void *)0);
}
/*
#include <stdio.h>
int main(void)
{
	char *s1 = "Hola mundo! ";
	printf("%s",ft_strrchr(s1,'a'));
	return (0);
}
*/
