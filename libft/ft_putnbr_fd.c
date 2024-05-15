/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:58:19 by alerome2          #+#    #+#             */
/*   Updated: 2024/05/14 20:12:11 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	*aux;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	aux = ft_itoa(n);
	if (!aux)
	{
		free(aux);
		return ;
	}
	if (fd && aux)
		write(fd, aux, ft_strlen(aux));
	free(aux);
}
/*
int main(void)
{
	int i = -295;
	int fd = 1;
	ft_putnbr_fd(i,fd);
	return (0);
}
*/
