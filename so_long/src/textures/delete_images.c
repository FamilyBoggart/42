/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:18:41 by alerome2          #+#    #+#             */
/*   Updated: 2024/11/12 12:44:13 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map[i]);
	free(map);
}

void	erase_collectible(t_coords *map)
{
	mlx_image_t	*image;
	mlx_image_t	**aux;
	int			i;

	i = 0;
	aux = map->c;
	while (i < map->p_col)
	{
		image = aux[i];
		if ((image->instances[0].x == map->player->instances[0].x)
			&& image->instances[0].y == map->player->instances[0].y)
			image->enabled = 0;
		i++;
	}
}

void	free_all(t_coords *map)
{
	free_map(map->map);
	free(map->c);
}
