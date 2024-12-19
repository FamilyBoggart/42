/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:50:29 by alerome2          #+#    #+#             */
/*   Updated: 2024/12/19 13:18:26 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/pipex.h"

char	*check_singlepath(char *path, char *cmd)
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
	aux = ft_strjoin("/", cmd_splitted[0]);
	fullpath = ft_strjoin(path, aux);
	free(aux);
	ft_free(cmd_splitted);
	if (access(fullpath, F_OK)== 0 && access(fullpath, X_OK) == 0)
		return(fullpath);
	else
		free(fullpath);
	return (NULL);
}

int	checkpaths(t_str *arg, char *cmd)
{
	int		i;
	char	*fullpath;

	i = 0;
	while(arg->paths[i])
	{
		fullpath = check_singlepath(arg->paths[i], cmd);
		if(fullpath)
		{
			arg->cmd[arg->i] = ft_strdup(cmd);
			arg->cmd_path[arg->i] = ft_strdup(fullpath);
			free(fullpath);
			return(1);
		}
		i++;
	}
	arg->cmd[arg->i] = NULL;
	arg->cmd_path[arg->i] = NULL;
	ft_free(arg->paths);
	return (0);
}

int	check_commands(t_str *str, char **args)
{
	str->cmd_path = malloc(sizeof(char *) * str->cmd_size);
	if(!str->cmd_path)
	{
		ft_free(str->cmd);
		return(0);
	}
	str->i = 0;
	while (str->i < str->cmd_size - 1)
	{
		str->paths = ft_split(str->envpath, ':');
		checkpaths(str, args[str->i + 2]);
		if (!str->cmd_path[str->i])
			return (0);
		else
			ft_printf("Command path: %s\n", str->cmd_path[str->i]);
		ft_free(str->paths);		
		str->i++;
	}
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
		str->input_file = args[1];
		str->envpath = getenv("PATH");
		str->cmd_size = argc - 2;
		str->cmd = malloc(sizeof(char *) * str->cmd_size);
		if(!str->cmd)
			return(NULL);
		if (check_commands(str, args))
			return (str);
	}
	finish(str, 0);
	free(str);
	return (NULL);
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
		command(arguments);
		finish(arguments, 1);
		free(arguments);
	}
	else
		ft_printf("Error\n");
	
	return (0);
}
