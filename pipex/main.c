/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:50:29 by alerome2          #+#    #+#             */
/*   Updated: 2024/12/11 11:28:32 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/pipex.h"

int check_singlepath(char *path, char *cmd)
{
	char	*fullpath;
	char	**cmd_splitted;
	char	*aux;

	if(ft_strchr(cmd, ' '))
		cmd_splitted = ft_split(cmd, ' ');
	else
	{
		cmd_splitted = malloc(sizeof (char *) * 2);
		cmd_splitted[0] = ft_strdup(cmd);
		cmd_splitted[1] = NULL;
	}
	aux = ft_strjoin(path, "/");
	fullpath = ft_strjoin(aux, cmd_splitted[0]);
	free(aux);
	ft_free(cmd_splitted);
	if (access(fullpath, F_OK)== 0 && access(fullpath, X_OK) == 0)
	{
		free(fullpath);
		return (1);
	}
	else
		free(fullpath);
	return (0);
}

int	checkpaths(t_str *arg, char *cmd)
{
	int		i;
	int		bool_check;

	i = 0;
	bool_check = 0;
	arg->paths = ft_split(arg->envpath, ':');
	while(arg->paths[i])
	{
		if(check_singlepath(arg->paths[i], cmd) == 1)
		{
			ft_printf("El comando %s se encuentra en %s\n", cmd, arg->paths[i]);
			bool_check = 1;
			break;
		}
				
		i++;
	}
	ft_free(arg->paths);
	return (bool_check);
}

int	check_commands(t_str *str, char **args, int argc)
{
	str->cmd = malloc(sizeof(char *) * (argc - 2));
	str->i = 0;
	while (str->i < argc - 3)
	{
		str->cmd[str->i] = ft_strdup(args[str->i + 2]);
		checkpaths(str, str->cmd[str->i]);
		str->i++;
	}
	str->cmd[str->i] = NULL;
	ft_free(str->cmd);
	return (1);
}

t_str *checkfiles(char **args, int argc)
{
	t_str	*str;
	
	str = malloc(sizeof(t_str));
	if (!str || access(args[1], F_OK) != 0)
	{
		if(str)
			free(str);
		return(NULL);
	}
	else
	{
		str->envpath = getenv("PATH");
		check_commands(str, args,  argc);
		return (str);
	}
}

int	main(int argc, char *argv[])
{
	t_str	*arguments;
	
	if (argc < 5)
	{
		ft_printf("Usage: ./pipex file1 cmd1 cmd2 file2\n");
		return (0);
	}
	arguments = checkfiles(argv, argc);
	if (arguments)
	{
		command(argv);
		free(arguments);
	}
	else
		ft_printf("Error\n");
	//write(2, "Esto es un error",16);
	return (0);
}
