/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:17:34 by alerome2          #+#    #+#             */
/*   Updated: 2024/05/01 18:57:21 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_memcmp(const void *s1, const void *s2, unsigned long n)
{
	unsigned char	*aux1;
	unsigned char	*aux2;
	unsigned long	i;

	aux1 = (unsigned char *)s1;
	aux2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (aux2[i] != aux1[i])
			return (aux1[i] - aux2[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
int main()
{

    char *s1 = "abcdefghij";
    char *s2= "abcdefgxyz";
    if(ft_memcmp(s1,s2,7) != 0)
        printf("ERROR");
    return 0;
}
*/
