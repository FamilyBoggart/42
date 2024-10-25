/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 19:43:33 by alerome2          #+#    #+#             */
/*   Updated: 2024/10/25 19:59:29 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"


void	render_images(void *mlx, t_textures *texture, char *img, t_coords cont)
{
	//.....................................................
}
*/

void	show_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			write(1, &map[i][j], 1);
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	rows(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	render_map(char **map, void *mlx, t_textures *texture)
{
	t_coords	counter;

	counter.x = 0;
	while (map[counter.x])
	{
		counter.y = 0;
		while (map[counter.x][counter.y])
		{
			if (map[counter.x][counter.y] == '1')
				render_images(mlx, texture, "Wall.png", counter);
			else
				render_images(mlx, texture, "Floor.png", counter);
			counter.y++;
		}
		counter.x++;
	}
}
