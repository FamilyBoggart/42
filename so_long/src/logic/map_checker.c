/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:37:38 by alerome2          #+#    #+#             */
/*   Updated: 2024/11/26 16:33:52 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	check_chars(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'P' && \
			map[i][j] != 'E' && map[i][j] != 'C')
			{
				if (!(map[i][j] == '\n' && map[i][j + 1] == 0))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_rectangular(t_coords *map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = ft_strlen(map->map[0]) - 1;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
			j++;
		if (map->map[i][j - 1] == '\n')
			j--;
		if (j != len)
			return (0);
		i++;
	}
	return (1);
}

int	rows(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	check_borders(t_coords *m)
{
	int	i;
	int	j;

	i = 0;
	m->map_columns = ft_strlen(m->map[0]) - 1;
	m->map_lines = rows(m->map);
	while (i < m->map_lines)
	{
		j = 0;
		while (j < m->map_columns)
		{
			if (m->map[i][j] == '\n' && m->map[i][j + 1] == 0)
				j++;
			else if (i == 0 || i == m->map_lines - 1
				|| j == 0 || j == m->map_columns - 1)
			{
				if (m->map[i][j] != '1')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_map(t_coords *map)
{
	if (!map)
		return (0);
	if (check_chars(map->map) && check_rectangular(map) && check_borders(map)
		&& only_one_player(map))
	{
		count_colectibles(map);
		if (floodfill(map))
		{
			free_map(map->f_map);
			return (1);
		}
		else
		{
			free_map(map->f_map);
			return (0);
		}
	}
	return (0);
}
