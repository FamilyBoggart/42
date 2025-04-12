/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:18:31 by alerome2          #+#    #+#             */
/*   Updated: 2025/04/12 18:06:28 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/pipex.h"

void	create_file(t_str *args, char *content)
{
	int	fd;

	fd = open(args->output_file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	write(fd, content, ft_strlen(content));
	close(fd);
}

char	*exec_process(char	**cmd, int *fd, int pid)
{
	char	*buf;
	int		fd_aux;

	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execv(cmd[0], cmd);
		close(fd[1]);
		exit(0);
	}
	else
	{
		wait(NULL);
		close(fd[1]);
		fd_aux = dup(fd[0]);
		buf = read_output(fd_aux);
		close(fd[0]);
		free(fd);
		ft_free(cmd);
		return (buf);
	}
}

char	**preparecmd(t_str	*args, char *input)
{
	char	**cmd;
	int		i;
	int		j;

	i = 0;
	while (args->cmd[args->j][i])
		i++;
	cmd = malloc(sizeof(char *) * (i + 1));
	cmd[0] = args->cmd_path[args->j];
	j = 1;
	while (j < i)
	{
		cmd[j] = ft_strdup(args->cmd[args->j][j]);
		j++;
	}
	cmd[j] = input;
	cmd[j + 1] = NULL;
	return (cmd);
}

void	command(t_str *args)
{
	char	**cmd;
	int		*fd;
	int		pid;
	char	*buffer;

	args->j = 0;
	while (args->j < args->i)
	{
		if (args->j == 0)
			cmd = preparecmd(args, args->input_file);
		else
			cmd = preparecmd(args, args->output_file);
		fd = malloc(sizeof(int) * 2);
		if (!fd)
			return ;
		if (pipe(fd) == -1)
			return ;
		pid = fork();
		if (pid == -1)
			return ;
		buffer = exec_process(cmd, fd, pid);
		create_file(args, buffer);
		free(buffer);
		args->j++;
	}
}
