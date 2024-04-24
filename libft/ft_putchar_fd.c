/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:04:26 by alerome2          #+#    #+#             */
/*   Updated: 2024/04/23 15:51:50 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	if (fd != -1)
		write(fd, &c, 1);
}
/*
#include <fcntl.h>
int main (void)
{
	int fd;

	fd = open("prueba.txt",O_RDWR)
	if(fd != -1)
		ft_putchar_fd('d',fd);
	return (0);
}
*/
