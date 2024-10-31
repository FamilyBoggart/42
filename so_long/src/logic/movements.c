/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:59:26 by alerome2          #+#    #+#             */
/*   Updated: 2024/10/31 14:16:17 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"
/*
void move_keyhook(mlx_key_data_t keydata, void* param)
{
	// If we PRESS the 'J' key, print "Hello".
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		puts("Hello ");

	// If we RELEASE the 'K' key, print "World".
	if (keydata.key == MLX_KEY_K && keydata.action == MLX_RELEASE)
		puts("World");Barcelona

	// If we HOLD the 'L' key, print "!".
	if (keydata.key == MLX_KEY_L && keydata.action == MLX_REPEAT)
		puts("!");
}
*/
void	key_movements(void *param)
{
	mlx_t		*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
			g_player->instances[0].y -= TS;
	else if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
			g_player->instances[0].y += TS;
	else if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
			g_player->instances[0].x -= TS;
	else if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
			g_player->instances[0].x += TS;
	
}
