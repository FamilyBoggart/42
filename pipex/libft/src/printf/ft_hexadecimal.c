/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:46:28 by alerome2          #+#    #+#             */
/*   Updated: 2024/07/17 12:17:12 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/printf/ft_printf.h"

int	write_hex(int b, int max)
{
	char	*hex;
	int		n;

	n = 0;
	if (!max)
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	n += ft_putchar(hex[b]);
	return (n);
}

int	ft_hexadecimal_u(size_t number, int max)
{
	size_t	a;
	int		b;
	int		n;

	n = 0;
	a = number / 16;
	b = number % 16;
	if (a > 0)
		n += ft_hexadecimal_u(a, max);
	n += write_hex(b, max);
	return (n);
}

int	ft_hexadecimal(int number, int max)
{
	size_t	a;
	int		b;
	size_t	u_number;
	int		n;

	if (number < 0)
		u_number = MAX_UINT + (number + 1);
	else
		u_number = number;
	a = u_number / 16;
	b = u_number % 16;
	n = 0;
	if (a > 0 && number >= 0)
		n += ft_hexadecimal(a, max);
	else if (a > 0 && number < 0)
		n += ft_hexadecimal_u(a, max);
	n += write_hex(b, max);
	return (n);
}
