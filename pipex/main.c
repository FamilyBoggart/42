/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:50:29 by alerome2          #+#    #+#             */
/*   Updated: 2024/12/04 18:04:40 by alerome2         ###   ########.fr       */
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
	if (access(fullpath, F_OK)== 0)
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
	char	*path;
	char	**paths;
	int		i;

	i = 0;
	path = getenv("PATH");
	paths = ft_split(path, ':');
	while(paths[i])
	{
		if (check_singlepath(paths[i], cmd), cmd)
			ft_printf("El comando %s se encuentra en %s\n", cmd, paths[i]);
		free(paths[i]);
		i++;
	}
	free(paths);
}

void accessfile(char *filename)
{
	if (access(filename, R_OK) == 0)
		ft_printf("El archivo es legible\n");
	if (access(filename, W_OK) == 0)
		ft_printf("El archivo es escribible\n");
	if (access(filename, X_OK) == 0)
		ft_printf("El archivo es ejecutable\n");
}

int	main(int argc, char *argv[])
{
	char *cmd1;

	if (argc != 5)
		return (0);
	// Primer test: ./pipex cat testfile1.txt
	cmd1 = ft_strdup(argv[1]);
	checkpaths(cmd1);
	free(cmd1);
	accessfile(argv[2]);

	return (0);
}