/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_renders.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:14:37 by alerome2          #+#    #+#             */
/*   Updated: 2024/10/25 18:20:48 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	render_map(void *mlx, t_textures *texture, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
			{
				texture->wall = mlx_load_png("./includes/Wall.png");
				mlx_image_to_window(mlx, texture->wall, j * 100, i * 100);
			}
			else
			{
				texture->floor = mlx_load_png("./includes/Floor.png");
				mlx_image_to_window(mlx, texture->floor, j * 100, i * 100);
			}
			j++;
		}
		i++;
	}
}