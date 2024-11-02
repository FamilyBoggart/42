/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:19:00 by alerome2          #+#    #+#             */
/*   Updated: 2024/11/02 15:40:02 by alerome2         ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	void		*mlx;
	t_textures	*textures;
	t_coords	*map;
	//mlx_image_t	*player;

	textures = malloc(sizeof(t_textures));
	if (argc != 2)
	{
		printf("Usage: %s <map.ber>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	map = create_map(argv[1]);
	if (!map->map)
	{
		printf("Error\n");
		return (0);
	}
	count_colectibles(map);
	ft_printf("(main.c) Collectibles in map: %d\n", map->total_collectibles); //Debug
	ft_printf("(main.c) Map_lines = %d, Map_columns = %d\n", map->map_lines, map->map_columns); //Debug
	mlx = mlx_init(map->map_columns * TS, map->map_lines * TS, "El camino de murciano", true);
	render_map(map, mlx, textures);
	/*
	//g_player = mlx_texture_to_image(mlx, texture);
	if (!mlx | ! g_player)
	{
		ft_error(mlx_errno);
		return (EXIT_FAILURE);
	}
	mlx_image_to_window(mlx, g_player, 0, 0);
	*/
	//mlx_loop_hook(mlx, key_movements, mlx);// No funciona
	mlx_key_hook(mlx, key_callback, map);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	free(textures);
	return (EXIT_SUCCESS);
}
