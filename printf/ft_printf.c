/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:39:09 by alerome2          #+#    #+#             */
/*   Updated: 2024/05/13 20:52:46 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int check_char(const char *text, int i)
{
	if (text[i + 1] == 'c')
		printf("Caracter");
	if (text[i + 1] == 's')
		printf("String");
	if (text[i + 1] == 'p')
		printf("Puntero void");
	if (text[i + 1] == 'd')
		printf("Double");
	if (text[i + 1] == 'i')
		printf("Integer");
	if (text[i + 1] == 'u')
		printf("Decimal en base 10");
	if (text[i + 1] == 'x')
		printf("Hexadecimal minus");
	if (text[i + 1] == 'X')
		printf("Hexadecimal Mayus");
	if (text[i + 1] == '%')
		printf("Simbolo de porcentaje");
	return (0);
}
int	ft_printf(const char *text,...)
{
	int		i;
	va_list args;
	va_start(args,text);
	i = 0;
	while (text[i] != '\0')
	{
		if (text[i] == '%')
			check_char(text, i);
		else
			write(1, &text[i], 1);
		i++;
	}
	write(1, "\0", 1);
	return (0);
}

int main()
{
	const char *s = "Hola Mundo";
	ft_printf(s);
	return (0);
}
