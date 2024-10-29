/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:19:00 by alerome2          #+#    #+#             */
/*   Updated: 2024/10/29 18:40:29 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

/*
static void	ft_error(mlx_errno_t mlx_errno)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

*/


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
	render_map(map.map, mlx, textures);
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
	mlx_loop_hook(mlx, key_movements, mlx);// Por ahora funciona
	mlx_loop(mlx);
	mlx_terminate(mlx);
	free(textures);
	return (EXIT_SUCCESS);
}
