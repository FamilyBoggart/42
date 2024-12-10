/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:50:29 by alerome2          #+#    #+#             */
/*   Updated: 2024/12/10 12:27:49 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/pipex.h"

int check_singlepath(char *path, char *cmd)
{
	char	*fullpath;
	char	*aux;

	aux = ft_strjoin(path, "/");
	fullpath = ft_strjoin(aux, cmd);
	free(aux);
	if (access(fullpath, F_OK)== 0 && access(fullpath, X_OK) == 0)
	{
		free(fullpath);
		return (1);
	}
	else
		free(fullpath);
	return (0);
}

void	checkpaths(char *cmd)
{
	t_str	*spath;
	int		i;

	i = 0;
	spath = malloc(sizeof(t_str));
	spath->path = getenv("PATH");
	spath->paths = ft_split(spath->path, ':');
	while(spath->paths[i])
	{
		if(ft_strchr(cmd, ' '))
		{
			spath->aux_path = ft_split(cmd,' ');
			if(check_singlepath(spath->paths[i], spath->aux_path[0]) == 1)
				ft_printf("El comando %s se encuentra en %s\n", spath->aux_path[0], spath->paths[i]);
			ft_free(spath->aux_path);
		}
		else
		{
			if (check_singlepath(spath->paths[i], cmd) == 1)
				ft_printf("El comando %s se encuentra en %s\n", cmd, spath->paths[i]);
		}	
		i++;
	}
	ft_free(spath->paths);
	free(spath);
}

int checkfiles(char **args)
{
	char *cmd1;
	char *cmd2;
	
	if (access(args[1], F_OK) == 0)
	{
		cmd1 = ft_strdup(args[2]);
		cmd2 = ft_strdup(args[3]);
		checkpaths(cmd1);
		checkpaths(cmd2);
		free(cmd1);
		free(cmd2);
		return (1);
	}
	else
	{
		ft_printf("Error. El archivo especificado no existe\n");
		return (0);
	}
}

int	main(int argc, char *argv[])
{
	if (argc != 5)
	{
		ft_printf("Usage: ./pipex file1 cmd1 cmd2 file2\n");
		return (0);
	}
	if (checkfiles(argv))
		command(argv);
	write(2, "Esto es un error",16);
	return (0);
}