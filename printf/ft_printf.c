/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:39:09 by alerome2          #+#    #+#             */
/*   Updated: 2024/05/16 17:23:16 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	clasify(va_list args, char format)
{
	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (format == 's')
		printf("String");
	if (format == 'p')
		printf("Puntero void");
	if (format == 'd')
		printf("Double");
	if (format == 'i')
		printf("Integer");
	if (format == 'u')
		printf("Decimal en base 10");
	if (format == 'x')
		printf("Hexadecimal minus");
	if (format == 'X')
		printf("Hexadecimal Mayus");
	if (format == '%')
		printf("Simbolo de porcentaje");
	return (0);
}

int	ft_printf(const char *text, ...)
{
	int		argument;
	va_list	args;
	int		i;

	i = 0;
	argument = 0;
	va_start(args, text);
	while (text[i] != '\0')
	{
		if (text[i] == '%')
			argument += clasify(args, text[++i]);
		i++;
	}
	return (argument);
}

int	main(void)
{
	const char	*s;

	s = "Hola Mundo";
	ft_printf(s);
	printf("Hola %c Mundo", 'a');
	return (0);
}
