/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 07:02:42 by alerome2          #+#    #+#             */
/*   Updated: 2024/04/15 19:46:50 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	size_n(int n)
{
	int	aux;
	int	size;

	size = 1;
	aux = n;
	while (aux >= 10)
	{
		aux = aux / 10;
		size = size * 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*s1;
	int		counter;
	int		size;

	if (n == -2147483648)
		return ("-2147483648");
	counter = 0;
	s1 = (char *) malloc(11);
	if (n < 0)
	{
		s1[counter] = '-';
		counter++;
		n = -n;
	}
	size = size_n(n);
	while (size >= 1)
	{
		s1[counter] = n / size + '0';
		n = n % size;
		size = size / 10;
		counter++;
	}
	free(s1);
	return (s1);
}
/*
#include <stdio.h>
int main(void)
{
	printf("%s",ft_itoa(2143648));
}
*/
