/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:18:31 by alerome2          #+#    #+#             */
/*   Updated: 2024/12/23 14:05:27 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/pipex.h"

void pipes(void)
{
	pid_t	pid_c;
	int		fd[2]; //Fd[0] lectura. fd[1] escritura
	char	buf[10]; //Buffer de lectura
	int		bytes_read;

	if (pipe(fd) == -1)
		ft_printf("Ha habido un error al crear el pipe\n");
	pid_c = fork();
	if (pid_c == -1)
		ft_printf("Error en el fork\n");
	else if( pid_c == 0)
	{
		close(fd[0]); //Cerramos lectura
		write(fd[1], "abcde", 5);
		close(fd[1]);
		exit(0);
	}
	else if (pid_c > 0)
	{
		ft_printf("PROCESO PADRE: %d\n", getpid());
		close(fd[1]); //Cerramos escritura
		bytes_read = read(fd[0], buf, sizeof(buf));
		ft_printf("Padre ha leido %d bytes:\t %s\n", bytes_read, buf);
		close(fd[0]);
		exit(0);
	}
	exit(1);
}

void	command(t_str *args)
{
	char	**cmd;
	int		*fd;
	int		pid;
	char	*buf[10];

/*
EJECUCION DEL COMANDO
*/
	cmd = malloc(sizeof(char *) * 3);
	cmd[0] = args->cmd_path[0];
	cmd[1] = args->input_file;
	cmd[2] = NULL;
/*
DISTRIBUCION DE PROCESOS
*/
	fd = malloc(sizeof(int) * 2);
	pipe(fd);
	pid = fork();
	if(pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO); //Rediriges el output a la escritura del pipe
		execv(cmd[0], cmd);
		close(fd[1]);
		exit(1);
	}
	else
	{
		wait(NULL);
		ft_printf("\033[31mPROCESO PADRE\n\033[0m");
		close(fd[1]);
		int br = read(fd[0], buf, sizeof(buf));
		if(br > 0)
			ft_printf("Buffer leido: %s", buf);
		close(fd[0]);
		free(fd);
		free(cmd);
	}
}
