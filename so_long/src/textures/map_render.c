/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 19:43:33 by alerome2          #+#    #+#             */
/*   Updated: 2024/11/12 12:32:44 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	render_collectible(t_coords *map, mlx_image_t *image)
{
	int	aux;

	if (map->p_col == 0)
	{
		aux = map->total_collectibles + 1;
		map->c = malloc(sizeof(mlx_image_t *) * aux);
		if (!map->c)
			return (EXIT_FAILURE);
		map->c[0] = image;
		map->p_col = 1;
	}
	else
	{
		map->c[map->p_col] = image;
		map->p_col++;
	}
	return (0);
}

int	render_sprite(t_coords *m, mlx_texture_t *texture)
{
	mlx_image_t	*aux;

	aux = mlx_texture_to_image(m->mlx, texture);
	if (!aux)
		return (EXIT_FAILURE);
	if (mlx_image_to_window(m->mlx, aux, m->x * TS, m->y * TS) == -1)
		return (EXIT_FAILURE);
	if (m->textures->collectible == texture)
		return (render_collectible(m, aux));
	if (m->textures->p == texture)
		m->player = aux;
	return (0);
}

void	init_render_map(t_coords *m, t_textures *t)
{
	m->y = 0;
	while (m->y < m->map_lines)
	{
		m->x = 0;
		while (m->x < m->map_columns)
		{
			if (m->map[m->y][m->x] == '1')
				render_sprite(m, t->wall);
			else
				render_sprite(m, t->floor);
			if (m->map[m->y][m->x] == 'C')
				render_sprite(m, t->collectible);
			else if (m->map[m->y][m->x] == 'E')
				render_sprite(m, t->exit);
			m->x++;
		}
		m->y++;
	}
}

void	init_textures(t_textures *texture)
{
	texture->wall = mlx_load_png("inc/Images/Wall.png");
	texture->floor = mlx_load_png("inc/Images/Floor.png");
	texture->exit = mlx_load_png("inc/Images/Exit.png");
	texture->p = mlx_load_png("inc/Images/Player.png");
	texture->collectible = mlx_load_png("inc/Images/collectible.png");
	ft_check_textures(texture);
}

void	render_map(t_coords *m, void *mlx, t_textures *texture)
{
	m->mlx = mlx;
	m->movements = 0;
	m->p_col = 0;
	init_textures(texture);
	m->textures = texture;
	init_render_map(m, texture);
	init_render_player(m, texture);
	ft_clean_textures(m->textures);
}
