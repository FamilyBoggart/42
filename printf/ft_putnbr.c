/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:59:41 by alerome2          #+#    #+#             */
/*   Updated: 2024/05/16 19:04:23 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	ft_putnbr(int number)
{
	char	*str;
	int		n;

	n = 0;
	str = ft_itoa(number);
	if (number < 0)
		n++;
	while(number > 0)
	{
		n++;
		number = number/10;
	}	
	write(1,str,n);
	return (n);
}