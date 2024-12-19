/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:18:31 by alerome2          #+#    #+#             */
/*   Updated: 2024/12/19 13:19:39 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/pipex.h"

void pipes(void)
{
	pid_t	pid_C;
	int 	fd[2]; //Fd[0] lectura. fd[1] escritura
	char	buf[10]; //Buffer de lectura
	int		bytes_read;

	if(pipe(fd) == -1)
		ft_printf("Ha habido un error al crear el pipe\n");
	pid_C = fork();
	if (pid_C == -1)
		ft_printf("Error en el fork\n");
	else if(pid_C == 0)
	{
		close(fd[0]); //Cerramos lectura
		write(fd[1], "abcde", 5);
		close(fd[1]);
		exit(0);
	}
	else if (pid_C > 0)
	{
		ft_printf("PROCESO PADRE: %d\n", getpid());
		close(fd[1]); //Cerramos escritura
		bytes_read = read(fd[0], buf, sizeof(buf));
		ft_printf("Padre ha leido %d bytes:\t %s\n",bytes_read, buf);
		close(fd[0]);
		exit(0);
	}
	exit(1);
}

void	command(t_str *args)
{
	ft_printf("Archivo a trabajar: %s\n", args->input_file);
}