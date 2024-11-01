/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:19:00 by alerome2          #+#    #+#             */
/*   Updated: 2024/11/01 11:29:42 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

/*
static void	ft_error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

*/
void showdimensions(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	ft_printf("Window size: x = %d, y = %d\n", mlx->width, mlx->height);
}

int	main(int argc, char *argv[])
{
	void		*mlx;
	t_textures	*textures;
	t_coords	map;

	textures = malloc(sizeof(t_textures));
	if (argc != 2)
	{
		printf("Usage: %s <map.ber>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	map = create_map(argv[1]);
	if (!map.map || map.x == 0 || map.y == 0)
	{
		printf("Error\n");
		return (0);
	}
	ft_printf("(main.c) Mapx Size: x = %d, y = %d\n", map.x * TS, map.y * TS);
	mlx = mlx_init(map.y * TS, map.x * TS, "Alerome2's game", true);

	//Create the player
	render_map(map.map, mlx, textures);
	mlx_image_t *player = mlx_texture_to_image(mlx, textures->p);
	mlx_image_to_window(mlx, player, 1 * TS, 1 * TS);
	ft_printf("(main.c) Player %p\n", player); //Debug
	ft_printf("(main.c) Player x: %d, y: %d\n", player->instances[0].x, player->instances[0].y); //Debug
	free(map.map);
	/*
	//g_player = mlx_texture_to_image(mlx, texture);
	if (!mlx | ! g_player)
	{
		ft_error(mlx_errno);
		return (EXIT_FAILURE);
	}
	mlx_image_to_window(mlx, g_player, 0, 0);
	*/
	//mlx_loop_hook(mlx, showdimensions, NULL);
	//mlx_loop_hook(mlx, key_movements, mlx);// No funciona
	mlx_key_hook(mlx, key_callback, player);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	free(textures);
	return (EXIT_SUCCESS);
}
