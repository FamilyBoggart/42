/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:59:26 by alerome2          #+#    #+#             */
/*   Updated: 2024/11/26 16:38:28 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	key_callback(mlx_key_data_t keydata, void *param)
{
	t_coords	*map;
	void		*mlx;

	map = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx = map->mlx;
		free_all(map);
		mlx_terminate(mlx);
		ft_printf("\033[91mDefeat...!\n\033[0m");
		exit(EXIT_SUCCESS);
	}
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
}

void	show_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			write(1, &map[i][j], 1);
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
}

void	move_if_possible(t_coords *map, int option)
{
	int	x;
	int	y;

	x = map->player->instances[0].x / TS;
	y = map->player->instances[0].y / TS;
	if (option == 1 && map->map[y - 1][x] != '1')
	{
		map->player->instances[0].y -= 1 * TS;
		ft_printf("\033[93mMovements: %d\n\033[0m", ++map->movements);
	}
	if (option == 2 && map->map[y + 1][x] != '1')
	{
		map->player->instances[0].y += 1 * TS;
		ft_printf("\033[93mMovements: %d\n\033[0m", ++map->movements);
	}
	if (option == 3 && map->map[y][x - 1] != '1')
	{
		map->player->instances[0].x -= 1 * TS;
		ft_printf("\033[93mMovements: %d\n\033[0m", ++map->movements);
	}
	if (option == 4 && map->map[y][x + 1] != '1')
	{
		map->player->instances[0].x += 1 * TS;
		ft_printf("\033[93mMovements: %d\n\033[0m", ++map->movements);
	}
}

void	exit_map(t_coords *map)
{
	int		x;
	int		y;
	void	*mlx;

	mlx = map->mlx;
	x = map->player->instances[0].x / TS;
	y = map->player->instances[0].y / TS;
	if (map->map[y][x] == 'E' && map->collected == map->total_collectibles)
	{
		ft_printf("\033[91mYou win!\n\033[0m");
		free_all(map);
		mlx_terminate(mlx);
		exit(EXIT_SUCCESS);
	}
}
