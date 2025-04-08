/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:50:29 by alerome2          #+#    #+#             */
/*   Updated: 2025/04/08 18:31:24 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/pipex.h"

/**
 * @brief Va a buscar el comando dado en el path dado y retorna si lo encontro
 * 
 * @param path 
 * @param cmd 
 * @return char* 
 */
char	*check_singlepath(char *path, char *cmd)
{
	char	*fullpath;
	char	**cmd_splitted;
	char	*aux;

	cmd_splitted = ft_split(cmd, ' ');
	aux = ft_strjoin("/", cmd_splitted[0]);
	fullpath = ft_strjoin(path, aux);
	free(aux);
	//Mirar las flags aqui
	ft_free(cmd_splitted);
	if (access(fullpath, F_OK) == 0 && access(fullpath, X_OK) == 0)
		return (fullpath);
	else
		free(fullpath);
	return (NULL);
}

/**
 * @brief Va a buscar el comando introducido en alguno de los PATHS de env
 * 
 * @param arg El objeto 
 * @param cmd El comando a buscar en algun path
 * @return int 
 */
int	checkpaths(t_str *arg, char *cmd)
{
	int		i;
	char	*fullpath;

	i = 0;
	while (arg->envpaths[i])
	{
		fullpath = check_singlepath(arg->envpaths[i], cmd);
		if (fullpath)
		{
			arg->cmd[arg->i] = ft_split(cmd, ' ');
			arg->cmd_path[arg->i] = ft_strdup(fullpath);
			free(fullpath);
			return (1);
		}
		i++;
	}
	arg->cmd[arg->i] = NULL;
	arg->cmd_path[arg->i] = NULL;
	ft_free(arg->envpaths);
	return (0);
}

int	check_commands(t_str *str, char **args)
{
	char	*path;

	path = getenv("PATH");
	str->envpaths = ft_split(path, ':');
	str->cmd_path = malloc(sizeof(char *) * str->cmd_size);
	if (!str->cmd_path)
	{
		ft_free(*str->cmd);
		free(str->cmd);
		return (0);
	}
	str->i = 0;
	while (str->i < str->cmd_size - 1)
	{
		checkpaths(str, args[str->i + 2]);
		if (!str->cmd_path[str->i])
			return (0);
		str->i++;
	}
	return (1);
}
/**
 * @brief La funcion access nos retorna 1 si el acceso 
 * 
 * @param args 
 * @param argc 
 * @return t_str* 
 */

t_str	*checkfiles(char **args, int argc)
{
	t_str	*str;

	str = malloc(sizeof(t_str));
	if (!str || access(args[1], F_OK) != 0)
	{
		if (str)
			free(str);
		return (NULL);
	}
	else
	{
		str->input_file = args[1];
		str->output_file = args[argc - 1];
		str->cmd_size = argc - 2;
		str->cmd = malloc(sizeof(char **) * str->cmd_size);
		if (!str->cmd)
			return (NULL);
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

	arguments = checkfiles(argv, argc);
	if (arguments)
	{
		test_read(arguments);
		command(arguments);
		finish(arguments, 1);
		free(arguments);
	}
	else
		ft_printf("(main)Error\n");
	return (0);
}
