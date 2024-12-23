/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:18:31 by alerome2          #+#    #+#             */
/*   Updated: 2024/12/23 18:18:27 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/pipex.h"

void pipes(void)
{
}

char	*exec_process(char	**cmd, int *fd, int pid)
{
	char	*buf;
	int		fd_aux;
	
	if(pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO); //Rediriges el output a la escritura del pipe
		execv(cmd[0], cmd);
		close(fd[1]);
		exit(0);
	}
	else
	{ //PROCESO PADRE
		wait(NULL);
		close(fd[1]);
		fd_aux = dup(fd[0]);
		buf = read_output(fd_aux);
		close(fd[0]);
		free(fd);
		free(cmd);
		return (buf);
	}
}

char	**preparecmd(t_str	*args, char *input)
{
	char	**cmd;
	int		i;

	i = 0;
	cmd = malloc(sizeof(char *) * 3);
	cmd[0] = args->cmd_path[i];
	cmd[1] = input;
	cmd[2] = NULL;
	return (cmd);
}

void	command(t_str *args)
{
	char	**cmd;
	int		*fd;
	int		pid;
	char	*buffer;

	cmd = preparecmd(args, args->input_file); //Preparacion del comando
	fd = malloc(sizeof(int) * 2);
	if (!fd)
		return ;
	if (pipe(fd) == -1)
		return ;
	pid = fork();
	if (pid == -1)
		return ;
	buffer = exec_process(cmd, fd, pid);
	ft_printf("Buffer:\t%s\n", buffer);
	//free(buffer);
	// 2ª ITERACION
	
	cmd = preparecmd(args, buffer); //Preparacion del comando
	ft_printf("cmd[0]:\t%s\n", cmd[0]);
	ft_printf("cmd[1]:\t%s\n", cmd[1]);
	//free(cmd);
	free(buffer);
	fd = malloc(sizeof(int) * 2);
	if (!fd)
		return ;
	if (pipe(fd) == -1)
		return ;
	pid = fork();
	if (pid == -1)
		return ;
	//free(fd);
	buffer = exec_process(cmd, fd, pid);
	free(buffer);
	/*
	buffer = exec_process(cmd, fd, pid);
	ft_printf("Buffer:\t%s\n", buffer);
	free(buffer);
	*/
	
	ft_printf("(command)Aqui solo llega el padre\n");

}
