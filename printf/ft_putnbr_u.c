/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:12:24 by alerome2          #+#    #+#             */
/*   Updated: 2024/05/23 15:27:32 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	u_n_size(unsigned int n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	ft_utoa(unsigned int number)
{
	char			*str;
	unsigned int	size;
	unsigned int	aux;

	size = u_n_size(number);
	aux = size;
	str = (char *)malloc(size + 1);
	if (!str)
		return (NULL);
	while (size > 0)
	{
		str[--size] = number % 10 + '0';
		number /= 10;
	}
	str[aux] = '\0';
	return (str);
}

int	ft_putnbr_u(int number)
{
	unsigned int	u_number;
	char			*str;
	int				len;

	if (number < 0)
		u_number = MAX_UINT + (number + 1);
	else
		u_number = number;
	str = ft_utoa(u_number);
	len = 0;
	while (str[len] != '\0')
	{
		ft_putchar(str[len]);
		len++;
	}
	free(str);
	return (len);
}
