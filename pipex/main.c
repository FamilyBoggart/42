/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:50:29 by alerome2          #+#    #+#             */
/*   Updated: 2024/08/03 11:19:06 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
int main(int argc, char *argv[])
{
	if(argc != 5)
	{
		return (0);
	}
	char *file1 = argv[1];
	char *cmd1 = argv[2];
	char *cmd2 = argv[3];
	char *file2 = argv[4];
	//Archivo de prueba para probar losp pipes
	int	fd[2]; //fd[0]: file descriptor de lectura del pipe, fd[1]: file descriptor de escritura del pipe
	int	pid;
	if (pipe(fd)== -1)
	{
		perror("pipe");
		return (1);
	}

	pid = fork();
	if(pid == -1)
	{
		perror("Fork");
		return (1);		
	}

	if(pid == 0) //Proceso hijo
	{
		close(fd[1]); //. Cerramos escritura y abrimos lectura
		char buffer[100];
		read(fd[0],buffer, sizeof(buffer));
		printf("Hijo recibio: %s", buffer);
		close(fd[0]);
	}
	else //Proceso padre
	{
		close(fd[0]);
		write(fd[1], "Hola desde el padre", 20);
		close(fd[1]);
	}
	
	return (0);
}