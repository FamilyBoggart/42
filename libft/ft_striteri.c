/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:33:19 by alerome2          #+#    #+#             */
/*   Updated: 2024/05/14 20:12:40 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int		i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
/*
void ft_toupper(unsigned int i, char* s)
{
	i = 0;
	*s = 'I';
}
int main()
{
	char *s = "Hola Mundo";
	ft_striteri(s,ft_toupper(3, s));
	return 0;
}
*/
