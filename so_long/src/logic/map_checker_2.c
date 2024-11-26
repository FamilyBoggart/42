/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:47:03 by alerome2          #+#    #+#             */
/*   Updated: 2024/11/26 15:55:47 by alerome2         ###   ########.fr       */
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

	ft_printf("Creating f_map \n");
	map->f_map = malloc(sizeof(char *) * (map->map_lines + 1));
	y = 0;
	while (y < map->map_lines)
	{
		x = 0;
		map->f_map[y] = malloc(map->map_columns);
		while (x < map->map_columns)
		{
			map->f_map[y][x] = map->map[y][x];
			x++;
		}
		y++;
	}
}

int	fill(t_coords *map, int x, int y)
{
	int		collectibles;
	char	c;

	collectibles = 0;
	if (!map->f_map)
		create_f_map(map);
	ft_printf("Map: %p, f_map: %p\n", map->map, map->f_map);
	c = map->f_map[y][x];
	ft_printf("c: %c\n", c);
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
	ft_printf("Lines: %d\nColumns: %d\n", map->map_lines, map->map_columns);
	while (map->y < map->map_lines)
	{
		map->x = 0;
		while (map->x < map->map_columns)
		{
			ft_printf("[%d][%d]: %c\n",map->y,map->x, map->map[map->y][map->x]);
			if (map->map[map->y][map->x] == 'P')
				collectibles = fill(map, map->x, map->y);
			map->x++;
		}
		map->y++;
	}
	ft_printf("Floodfill collectibles: %d\nTotal collectibles: %d\n",collectibles, map->total_collectibles);
	if (collectibles != map->total_collectibles)
		return (0);
	else
		return (1);
}
