/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@sutdent.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:15:04 by alerome2          #+#    #+#             */
/*   Updated: 2024/05/17 12:15:15 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
#include <stdio.h>

int	clasify(va_list args, char format)
{
	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (format == 'p')
		printf("Puntero void");
	if (format == 'd')
		return (ft_putnbr(va_arg(args, int)));
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
			argument += ft_putchar(text[i]);
		i++;
	}
	return (argument);
}
// Comentar de aqui hasta abajo
#include <stdlib.h>
#include <stdio.h>
void	ft_leaks(void)
{
	system("valgrind --tool=memcheck --leak-check=yes ./a.out");
}

int	main(void)
{
	
	int n = ft_printf("Hola %c %s %c , nº %i %% %d\n",'a',"Mundo",'b',-7, -10);
	int aux =  printf("Hola %c %s %c , nº %i %% %d\n",'a',"Mundo",'b',-7,-10);
	ft_printf("\nBytes usados: %i, printf: %i\n",n,aux);
	//atexit(ft_leaks);
	return (0);
}
