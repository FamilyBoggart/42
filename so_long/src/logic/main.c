/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:19:00 by alerome2          #+#    #+#             */
/*   Updated: 2024/11/26 16:13:55 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

/*
atexit(ft_end);
void	ft_end(void)
{	
	system("leaks -q ./so_long maps/map_00.ber");
}
*/

int	main(int argc, char *argv[])
{
	void		*mlx;
	t_textures	*textures;
	t_coords	*map;

	if (argc != 2)
	{
		printf("Usage: %s <map.ber>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	textures = malloc(sizeof(t_textures));
	map = create_map(argv[1]);
	if (!map)
	{
		printf("Error\n");
		exit(EXIT_FAILURE);
	}
	mlx = mlx_init(map->map_columns * TS, map->map_lines * TS, "so_long", true);
	render_map(map, mlx, textures);
	mlx_key_hook(mlx, key_callback, map);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	free(textures);
	return (EXIT_SUCCESS);
}
