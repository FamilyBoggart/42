/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:42:56 by alerome2          #+#    #+#             */
/*   Updated: 2024/10/29 10:53:38 by alerome2         ###   ########.fr       */
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

char	**parse_map(char *arg)
{
	int		lines;
	int		fd;
	int		i;
	char	**map;

	lines = count_lines_map(arg);
	if (lines == 0)
		return (NULL);
	fd = open(arg, O_RDONLY);
	map = (char **)malloc(sizeof(char *) * (lines + 1));
	i = 0;
	while (i < lines)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	return (map);
}

void	create_map(char *arg, void *mlx, t_textures *textures)
{
	char	**map;

	map = NULL;
	if (check_ber(arg))
		map = parse_map(arg);
	if (map)
	{
		if (check_map(map))
			show_map(map);
		else
			ft_printf("(map reader) Mapa no valido\n");
	}
	else
		ft_printf("(map reader) Error al leer el archivo\n");
	render_map(map, mlx, textures);
	free_map(map);
}
