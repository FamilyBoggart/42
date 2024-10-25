/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 20:15:48 by alerome2          #+#    #+#             */
/*   Updated: 2024/07/18 20:15:05 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft/libft.h"
#include "../inc/printf/ft_printf.h"

int	main(void)
{
	char	*s1;

	s1 = malloc(100 * sizeof(char));
	s1 = "	-46yugyg5d6";
	ft_printf("ft_ atoi: %d\n", ft_atoi(s1));
	s1 = "Hola Mundo";
	ft_printf(ft_bzero(s1, 7));
	return (0);
}
