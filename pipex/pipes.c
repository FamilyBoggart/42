/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:18:31 by alerome2          #+#    #+#             */
/*   Updated: 2024/12/23 17:23:57 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/pipex.h"

void pipes(void)
{
}

void	exec_process(char	**cmd, int *fd, int pid)
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
		ft_printf("Buffer: %s\n", buf);
		close(fd[0]);
		free(buf);
		free(fd);
		free(cmd);
	}
}

char	**preparecmd(t_str	*args)
{
	char	**cmd;
	int		i;

	i = 0;
	cmd = malloc(sizeof(char *) * 3);
	cmd[0] = args->cmd_path[i];
	cmd[1] = args -> input_file;
	cmd[2] = NULL;
	return (cmd);
}

void	command(t_str *args)
{
	char	**cmd;
	int		*fd;
	int		pid;

	cmd = preparecmd(args); //Preparacion del comando
	fd = malloc(sizeof(int) * 2);
	if (!fd)
		return ;
	if (pipe(fd) == -1)
		return ;
	pid = fork();
	if (pid == -1)
		return ;
	exec_process(cmd, fd, pid);
	ft_printf("(command)Aqui solo llega el padre\n");

}
