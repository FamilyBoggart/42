/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@sutdent.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:12:24 by alerome2          #+#    #+#             */
/*   Updated: 2024/05/17 12:12:32 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int ft_putnbr_u(unsigned int u_number)
{
	return (ft_putnbr((int)u_number));
}
