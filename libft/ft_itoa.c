/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:43:15 by alerome2          #+#    #+#             */
/*   Updated: 2024/05/14 20:10:38 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	n_size(int n)
{
	int	counter;

	counter = 0;
	while (n != 0)
	{
		n /= 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*aux;
	int		res;

	size = n_size(n);
	if (n < 0 || n == 0)
		size++;
	aux = (char *)malloc(size + 1);
	if (!aux)
		return (NULL);
	aux[size] = '\0';
	if (n < 0)
		aux[0] = '-';
	else if (n == 0)
		aux[0] = '0';
	while (n != 0)
	{
		res = n % 10;
		if (res < 0)
			res = -res;
		n /= 10;
		aux[--size] = res + '0';
	}
	return (aux);
}
