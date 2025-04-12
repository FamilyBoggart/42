/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 18:43:28 by alerome2          #+#    #+#             */
/*   Updated: 2025/04/12 20:56:17 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	test_read(t_str	*args)
{
	ft_printf("Input file: %s\n", args->input_file);
	ft_printf("Output file: %s\n", args->output_file);
	ft_printf("Cmd size: %d\n", args->cmd_size);
}

int	check_commands(t_str *args, char **argv)
{
	char	*path;
	int		i;

	path = getenv("PATH");
	args->envpaths = ft_split(path, ':');
	i = 0;
	while (args->envpaths[i])
		ft_printf("Path: %s\n", args->envpaths[i++]);
	ft_printf("test: %s\n", argv[0]);
	return (0);
}

t_str	*check(int argc, char	**argv)
{
	t_str	*args;

	args = malloc(sizeof(t_str));
	if (!args || access(argv[1], F_OK != 0))
	{
		if (args)
			free(args);
		return (NULL);
	}
	else
	{
		args->input_file = argv[1];
		args->output_file = argv[argc - 1];
		args->cmd_size = argc - 2;
		args->cmd = malloc(sizeof(char **) * args->cmd_size);
		if (!args->cmd)
			return (NULL);
		if (check_commands(args, argv))
			return (args);
	}
	ft_free(args);
	return (NULL);
}
