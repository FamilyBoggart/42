/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:42:56 by alerome2          #+#    #+#             */
/*   Updated: 2024/11/06 14:58:11 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	check_ber(char *arg)
{
	char	*aux;

	aux = arg;
	while (*aux)
		aux++;
	while (*arg != *aux)
	{
		if (*aux == '.')
		{
			if (aux[1] == 'b' && aux[2] == 'e' && aux[3] == 'r' && aux[4] == 0)
				return (1);
		}
		aux--;
	}
	return (0);
}

int	count_lines_map(char *arg)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(arg, O_RDONLY);
	if (fd < 0)
		return (0);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (i);
}

t_coords	*parse_map(char *arg)
{
	int			lines;
	int			fd;
	int			i;
	t_coords	*map;

	map = malloc(sizeof(t_coords));
	lines = count_lines_map(arg);
	map->map = NULL;
	if (lines == 0)
		return (map);
	fd = open(arg, O_RDONLY);
	map->map = (char **)malloc(sizeof(char *) * (lines + 1));
	i = 0;
	while (i < lines)
	{
		map->map[i] = get_next_line(fd);
		i++;
	}
	map->map[i] = NULL;
	return (map);
}

t_coords	*create_map(char *arg)
{
	t_coords	*map;

	if (check_ber(arg))
		map = parse_map(arg);
	else
	{
		map = NULL;
		return (map);
	}
	if (map->map)
	{
		if (check_map(map))
			return (map);
		else
		{
			free_map(map->map);
			return (map);
		}
	}
	else
		ft_printf("(map reader) Error al leer el archivo\n");
	return (map);
}
