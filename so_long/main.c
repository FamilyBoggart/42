/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:19:00 by alerome2          #+#    #+#             */
/*   Updated: 2024/10/18 12:13:26 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_error(mlx_errno_t mlx_errno)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	key_movements(void *param)
{
	mlx_t		*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	else if (mlx_is_key_down(mlx, MLX_KEY_UP))
		g_player->instances[0].y -= 20;
	else if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		g_player->instances[0].y += 20;
	else if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		g_player->instances[0].x -= 20;
	else if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		g_player->instances[0].x += 20;
}

int	main(int argc, char *argv[])
{
	void				*mlx;
	mlx_texture_t		*p_texture;
	char				**map;

	if (argc != 2)
	{
		printf("Usage: %s <map.ber>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	map = generate_map();
	show_map(map);
	mlx = mlx_init(WIDTH, HEIGHT, "Alerome2's game", true);
	p_texture = mlx_load_png("./includes/player.png");
	g_player = mlx_texture_to_image(mlx, p_texture);
	if (!mlx | ! g_player)
	{
		ft_error(mlx_errno);
		return (EXIT_FAILURE);
	}
	mlx_image_to_window(mlx, g_player, 0, 0);
	mlx_loop_hook(mlx, key_movements, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
