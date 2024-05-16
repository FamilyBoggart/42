/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:39:09 by alerome2          #+#    #+#             */
/*   Updated: 2024/05/16 19:05:41 by alerome2         ###   ########.fr       */
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
		return (ft_putnbr(va_arg(args, int)));
	if (format == 'u')
		printf("Decimal en base 10");
	if (format == 'x')
		printf("Hexadecimal minus");
	if (format == 'X')
		printf("Hexadecimal Mayus");
	if (format == '%')
		return (ft_putchar('%'));
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
		else
			ft_putchar(text[i]);
		i++;
	}
	return (argument);
}
// Comentar de aqui hasta abajo
#include <stdlib.h>
void	ft_leaks(void)
{
	system("leaks -q programa");
}

int	main(void)
{
	const char	*s;

	//atexit(ft_leaks);
	s = "Hola Mundo";
	int n = ft_printf("Hola %c Mundo %c %%",'a','b');
	ft_printf("\nNumero de bytes usados: %d",s);
	return (0);
}
