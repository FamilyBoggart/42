/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:14:02 by alerome2          #+#    #+#             */
/*   Updated: 2024/11/28 12:07:45 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/printf/ft_printf.h"

int	n_size_pf(int n)
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

char	*ft_itoa_pf(int n)
{
	int		size;
	char	*aux;
	int		res;

	size = n_size_pf(n);
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
	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	str = ft_itoa_pf(number);
	if (number <= 0)
	{
		n++;
		number = -number;
	}
	while (number > 0)
	{
		n++;
		number = number / 10;
	}
	write(1, str, n);
	free(str);
	return (n);
}
