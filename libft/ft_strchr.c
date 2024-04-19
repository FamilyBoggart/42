/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:40:38 by alerome2          #+#    #+#             */
/*   Updated: 2024/04/16 13:58:31 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return (s);
		s++;
	}
	if (*s == (char)c)
		return (s);
	else
		return ((void *)0);
}
/*
#include <stdio.h>
int main (void)
{
	char *s1 = "Hola mundo";
	for(int i = 0;i <256; i++)
	{
		if(!(ft_strchr(s1,i)))
			printf("NULL\n");
		else
			printf("%s\n",ft_strchr(s1,i));
	}
	return 0;
}
*/
