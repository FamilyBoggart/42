/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:18:31 by alerome2          #+#    #+#             */
/*   Updated: 2024/12/09 18:23:18 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/pipex.h"

void command(char *argv[])
{
	int	fd_in;
	//int	fd_out;

	fd_in = open(argv[0], O_RDONLY);
	if (fd_in != -1)
		ft_printf("Archivo leido correctamente\n");
	close(fd_in);
}