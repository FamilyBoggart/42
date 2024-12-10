/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:50:29 by alerome2          #+#    #+#             */
/*   Updated: 2024/12/10 12:47:42 by alerome2         ###   ########.fr       */
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

void	checkpaths(t_str *arg, char *cmd)
{
	int		i;

	i = 0;
	arg->paths = ft_split(arg->envpath, ':');
	while(arg->paths[i])
	{
		if(ft_strchr(cmd, ' '))
		{
			arg->aux_path = ft_split(cmd,' ');
			if(check_singlepath(arg->paths[i], arg->aux_path[0]) == 1)
				ft_printf("El comando %s se encuentra en %s\n", arg->aux_path[0], arg->paths[i]);
			ft_free(arg->aux_path);
		}
		else
		{
			if (check_singlepath(arg->paths[i], cmd) == 1)
				ft_printf("El comando %s se encuentra en %s\n", cmd, arg->paths[i]);
		}	
		i++;
	}
	ft_free(arg->paths);
}

t_str *checkfiles(char **args)
{
	t_str	*arguments;
	
	arguments = malloc(sizeof(t_str));
	if (access(args[1], F_OK) == 0)
	{
		arguments->cmd1 = ft_strdup(args[2]);
		arguments->cmd2 = ft_strdup(args[3]);
		arguments->envpath = getenv("PATH");
		checkpaths(arguments, arguments->cmd1);
		checkpaths(arguments, arguments->cmd2);
		free(arguments->cmd1);
		free(arguments->cmd2);
		return (arguments);
	}
	else
	{
		free(arguments);
		ft_printf("Error. El archivo especificado no existe\n");
		return (NULL);
	}
}

int	main(int argc, char *argv[])
{
	t_str	*arguments;
	
	if (argc != 5)
	{
		ft_printf("Usage: ./pipex file1 cmd1 cmd2 file2\n");
		return (0);
	}
	arguments = checkfiles(argv);
	if (arguments)
	{
		command(argv);
		free(arguments);
	}
	//write(2, "Esto es un error",16);
	return (0);
}