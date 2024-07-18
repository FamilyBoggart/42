/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:38:04 by alerome2          #+#    #+#             */
/*   Updated: 2024/07/18 20:07:31 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft/libft.h"

unsigned long	ft_strlcat(char *dst, const char *src, unsigned long dstsize)
{
	size_t	i;
	size_t	j;
	size_t	a;

	i = 0;
	j = 0;
	a = 0;
	while (dst[i] != '\0')
		i++;
	while (src[a] != '\0')
		a++;
	if (i <= dstsize)
		a += i;
	else
		a += dstsize;
	while (src[j] != '\0' && (i + 1) < dstsize)
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	return (a);
}
/*
#include <string.h>
#include <stdio.h>
int main(void)
{	
	char *s1= "lorem ipsum dolor sit amet";
	char s2[26];

	s2[10] = 'a';
	
	strlcat(s2,s1,0);
	printf("\n%s%lu\n",s2,strlcat(s2,s1,0));
	
//	ft_strlcat(s2,s1,sizeof(s2));
//	printf("%s\n", s2,ft_strlcat(s2,s1,0));
	return 0;
}
*/
