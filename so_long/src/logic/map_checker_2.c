/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:47:03 by alerome2          #+#    #+#             */
/*   Updated: 2024/11/18 16:27:23 by alerome2         ###   ########.fr       */
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

int	fill(t_coords *map, int x, int y)
{
	int	collectibles;

	collectibles = 0;
	if (!map->f_map)
		map->f_map = map->map;
	map->fill_char = 'F';
	ft_printf("f_map[y][x] = %c\n", map->f_map[y][x]);
	if (y < 0 || y > map->map_lines || x < 0
		|| x > map->map_columns || map->f_map[y][x] != 'P')
		return (collectibles);
	if (map->f_map[y][x] == 'C')
		collectibles++;
	map->f_map[y][x] = 'P';
	collectibles += fill (map, x - 1, y);
	collectibles += fill (map, x + 1, y);
	collectibles += fill (map, x, y - 1);
	collectibles += fill (map, x, y + 1);
	return (collectibles);
}

int	floodfill(t_coords *map)
{
	int	collectibles;
	int	x;
	int	y;
	int	i;
	int	j;

	x = map->p_x;
	y = map->p_y;
	ft_printf("x: %d, y= %d\n", x, y);
	collectibles = fill (map, x, y);
	ft_printf("Collectibles : %d\n", collectibles);
	i = 0;
	while (i < map->map_lines)
	{
		j = 0;
		while (j < map->map_columns)
		{
			ft_printf("%c", map->f_map[y][x]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	return (0);
}
