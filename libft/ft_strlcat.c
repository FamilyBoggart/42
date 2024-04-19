/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:38:04 by alerome2          #+#    #+#             */
/*   Updated: 2024/04/19 13:48:16 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_strlcat(char *dst, const char *src, unsigned long dstsize)
{
	unsigned long	i;
	unsigned long	j;
	char			*aux_src;
	unsigned long	total_size;

	aux_src = (char *)src;
	i = 0;
	j = 0;
	while (dst[i] != '\0' && i < dstsize)
		i++;
	total_size = ft_strlen(src) + i;
	while (i < dstsize - 1)
	{
		dst[i] = aux_src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (total_size);
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
