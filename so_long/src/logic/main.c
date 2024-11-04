/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:19:00 by alerome2          #+#    #+#             */
/*   Updated: 2024/11/04 17:46:36 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	main(int argc, char *argv[])
{
	void		*mlx;
	t_textures	*textures;
	t_coords	*map;

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
	mlx = mlx_init(map->map_columns * TS, map->map_lines * TS, "El camino de murciano", true);
	render_map(map, mlx, textures);
	mlx_key_hook(mlx, key_callback, map);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	free(textures);
	return (EXIT_SUCCESS);
}
