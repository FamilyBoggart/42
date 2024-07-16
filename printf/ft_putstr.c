/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:13:31 by alerome2          #+#    #+#             */
/*   Updated: 2024/07/16 14:17:06 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	n;

	if (!str)
		return (ft_putstr("(null)"));
	n = 0;
	while (str[n] != '\0')
		n += ft_putchar(str[n]);
	return (n);
}
