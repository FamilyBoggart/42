/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 19:43:33 by alerome2          #+#    #+#             */
/*   Updated: 2024/11/02 16:01:32 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"


void	render_images(void *mlx, t_textures *texture, t_coords *m)
{
	mlx_image_t	*img;
	

	ft_printf("Map[%d][%d] = %c\n", m->x, m->y, m->map[m->y][m->x]);
	if(m->map[m->y][m->x] == '1')
		img = mlx_texture_to_image(mlx, texture->wall);
	else
		img = mlx_texture_to_image(mlx, texture->floor);
	mlx_image_to_window(mlx, img, m->x * TS, m->y * TS);
	if(m->map[m->y][m->x] == 'E')
		img = mlx_texture_to_image(mlx, texture->exit);
	if(m->map[m->y][m->x] == 'C')
		img = mlx_texture_to_image(mlx, texture->c_libft);
	if(m->map[m->y][m->x] == 'P')
	{
		m->player = mlx_texture_to_image(mlx, texture->p);
		mlx_image_to_window(mlx, m->player, m->x * TS, m->y * TS);
		ft_printf("Player position: [%d,%d]\n", m->player->instances[0].x, m->player->instances[0].y);
	}
	else
		mlx_image_to_window(mlx, img, m->x * TS, m->y * TS);
}


void init_textures(t_textures *texture)
{
	char *path;

	path = "/home/usuario/Desktop/42/so_long/inc/Images/";
	texture->wall = mlx_load_png(ft_strjoin(path, "Wall.png"));
	texture->floor = mlx_load_png(ft_strjoin(path, "Floor.png"));
	texture->exit = mlx_load_png(ft_strjoin(path, "Exit.png"));
	texture->p = mlx_load_png(ft_strjoin(path, "Player.png"));
	texture->c_libft = mlx_load_png(ft_strjoin(path, "c_libft.png"));
	texture->c_printf = mlx_load_png(ft_strjoin(path, "c_printf.png"));
	texture->c_gnl = mlx_load_png(ft_strjoin(path, "c_gnl.png"));
	texture->c_b2br = mlx_load_png(ft_strjoin(path, "c_b2br.png"));
	texture->c_locked = mlx_load_png(ft_strjoin(path, "c_locked.png"));
}
/*
void	show_map(char **map)
{
	int	i;	t_player	player;
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
*/

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

/**
 * @brief Primero renderiza las texturas de las celdas del mapa, luego renderiza la textura del jugador
 * 
 * @param m 
 * @param mlx 
 * @param texture 
 */
void render_map(t_coords *m, void *mlx, t_textures *texture)
{
	int	player_x;
	int	player_y;
	
	init_textures(texture);
	m->y = 0;
	while (m->y < m->map_lines)
	{
		m->x = 0;
		while (m->x < m->map_columns)
		{
			if (m->map[m->y][m->x] == 'P')
			{
				player_x = m->x;
				player_y = m->y;
			}
			else
				render_images(mlx, texture, m);
			m->x++;
		}
		m->y++;
	}
	m->x = player_x;
	m->y = player_y;
	render_images(mlx, texture, m);
}
