/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:47:03 by alerome2          #+#    #+#             */
/*   Updated: 2024/11/26 16:29:50 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	only_one_player(t_coords *map)
{
	int	player;

	map->y = 0;
	player = 0;
	while (map->map[map->y])
	{
		map->x = 0;
		while (map->map[map->y][map->x])
		{
			if (map->map[map->y][map->x] == 'P')
			{
				player++;
				map->p_x = map->x;
				map->p_y = map->y;
			}
			map->x++;
		}
		map->y++;
	}
	if (player != 1)
		return (0);
	return (1);
}

void	create_f_map(t_coords *map)
{
	int		y;
	int		x;

	map->f_map = malloc(sizeof(char *) * (map->map_lines + 1));
	y = 0;
	while (y < map->map_lines)
	{
		x = 0;
		map->f_map[y] = malloc(map->map_columns + 2);
		while (x < map->map_columns)
		{
			map->f_map[y][x] = map->map[y][x];
			x++;
		}
		map->f_map[y][x] = '\n';
		map->f_map[y][x + 1] = '\0';
		y++;
	}
	map->f_map[y] = NULL;
}

int	fill(t_coords *map, int x, int y)
{
	int		collectibles;
	char	c;

	collectibles = 0;
	if (!map->f_map)
		create_f_map(map);
	c = map->f_map[y][x];
	if (c != '1' && c != '*')
	{
		if (c == 'E')
			map->exit++;
		if (c == 'C')
			collectibles++;
		map->f_map[y][x] = '*';
		if (y - 1 >= 0)
			collectibles += fill (map, x, y - 1);
		if (y + 1 < map->map_lines)
			collectibles += fill (map, x, y + 1);
		if (x - 1 >= 0)
			collectibles += fill (map, x - 1, y);
		if (x + 1 < map->map_columns)
			collectibles += fill (map, x + 1, y);
	}
	return (collectibles);
}

int	floodfill(t_coords *map)
{
	int	collectibles;

	map->exit = 0;
	map->y = 0;
	map->f_map = NULL;
	while (map->y < map->map_lines)
	{
		map->x = 0;
		while (map->x < map->map_columns)
		{
			if (map->map[map->y][map->x] == 'P')
				collectibles = fill(map, map->x, map->y);
			map->x++;
		}
		map->y++;
	}
	if (collectibles != map->total_collectibles)
		return (0);
	else
		return (1);
}
