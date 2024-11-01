/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:59:26 by alerome2          #+#    #+#             */
/*   Updated: 2024/11/01 11:32:12 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"
/*
void move_keyhook(mlx_key_data_t keydata, void* param)
{
	// If we PRESS the 'J' key, ft_printf "Hello".
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		puts("Hello ");

	// If we RELEASE the 'K' key, ft_printf "World".
	if (keydata.key == MLX_KEY_K && keydata.action == MLX_RELEASE)
		puts("World");Barcelona

	// If we HOLD the 'L' key, ft_printf "!".
	if (keydata.key == MLX_KEY_L && keydata.action == MLX_REPEAT)
		puts("!");
}
*/

void key_callback(mlx_key_data_t keydata, void *param)
{
	mlx_image_t	*player;

	player = param;

	ft_printf("Key action: %d\n", keydata.action);
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		player->instances[0].y -= 1 * TS;
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		player->instances[0].y += 1 * TS;
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		player->instances[0].x -= 1 * TS;
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		player->instances[0].x += 1 * TS;
}
