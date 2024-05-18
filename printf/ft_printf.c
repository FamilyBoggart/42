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
		return (ft_putnbr_u(va_arg(args,int)));
	if (format == 'x')
		return(ft_hexadecimal(va_arg(args,int),0));
	if (format == 'X')
		return(ft_hexadecimal(va_arg(args,int),1));
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
/*
void	ft_leaks(void)
{
	system("valgrind --tool=memcheck --leak-check=yes ./a.out");
}
*/

