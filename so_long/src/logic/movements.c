/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:59:26 by alerome2          #+#    #+#             */
/*   Updated: 2024/11/01 17:35:08 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void key_callback(mlx_key_data_t keydata, void *param)
{
	t_coords	*map;
	mlx_image_t	*player;

	map = param;
	player = map->player;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit(EXIT_SUCCESS);
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		move_if_possible(map, 1);
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		move_if_possible(map, 2);
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		move_if_possible(map, 3);
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		move_if_possible(map, 4);
	collect(map);
	exit_map(map);
	ft_printf("Player position: x = %d, y = %d\n", player->instances[0].x, player->instances[0].y);
	ft_printf("Map char: %c\n", map->map[player->instances[0].x / TS][player->instances[0].y / TS]);
}

void move_if_possible(t_coords *map, int option)
{
	mlx_image_t	*player;
	int x;
	int y;

	x = map->player->instances[0].x / TS;
	y = map->player->instances[0].y / TS;
	ft_printf("(move_if_possible) Player position: x = %d, y = %d\n", x, y);
	player = map->player;
	player->instances[0].z = -1;
	if (option == 1 && map->map[x - 1][y] != '1')
		player->instances[0].x -= 1 * TS;
	if (option == 2 && map->map[x + 1][y] != '1')
		player->instances[0].x += 1 * TS;
	if (option == 3 && map->map[x][y - 1] != '1')
		player->instances[0].y -= 1 * TS;
	if (option == 4 && map->map[x][y + 1] != '1')
		player->instances[0].y += 1 * TS;
}

void exit_map(t_coords *map)
{
	int x;
	int y;

	x = map->player->instances[0].x / TS;
	y = map->player->instances[0].y / TS;
	if (map->map[x][y] == 'E' && map->collected == map->total_collectibles)
	{
		ft_printf("\033[91mYou win!\n\033[0m");
		exit(EXIT_SUCCESS);
	}
}
