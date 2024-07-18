/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:02:37 by alerome2          #+#    #+#             */
/*   Updated: 2024/07/16 14:41:32 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_putptr(size_t ptr)
{
	int	n;

	if (!ptr)
		return (ft_putstr("(nil)"));
	ft_putstr("0x");
	n = ft_hexadecimal_u(ptr, 0);
	return (n + 2);
}
