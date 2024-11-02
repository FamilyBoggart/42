/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 19:43:33 by alerome2          #+#    #+#             */
/*   Updated: 2024/11/02 12:32:23 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"


void	render_images(void *mlx, t_textures *texture, char *path, t_coords cont)
{
	mlx_image_t	*img;
	
	if (ft_strncmp(path, "Player.png", 10))
	{
		if (!ft_strncmp(path, "Wall.png", 8))
			img = mlx_texture_to_image(mlx, texture->wall);
		if (!ft_strncmp(path, "Floor.png", 9))
			img = mlx_texture_to_image(mlx, texture->floor);
		if (!ft_strncmp(path, "Exit.png", 8))
			img = mlx_texture_to_image(mlx, texture->exit);
		if (!ft_strncmp(path, "c_libft.png", 11))
			img = mlx_texture_to_image(mlx, texture->c_libft);
		mlx_image_to_window(mlx, img, cont.y * TS, cont.x * TS);
	}	
	else 
	{
		g_player = mlx_texture_to_image(mlx, texture->p);
		mlx_image_to_window(mlx, g_player, cont.y * TS, cont.x * TS);
	}

}

mlx_image_t *render_player(void *mlx, t_textures *texture, t_coords cont)
{
	mlx_image_t	*img;

	img = mlx_texture_to_image(mlx, texture->p);
	mlx_image_to_window(mlx, img, cont.y * TS, cont.x * TS);
	return (img);
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


mlx_image_t	*render_map(t_coords *m, void *mlx, t_textures *texture)
{
	t_coords	counter;
	mlx_image_t	*player;

	init_textures(texture);
	counter.x = 0;
	while (m->map[counter.x])
	{
		counter.y = 0;
		while (m->map[counter.x][counter.y])
		{
			if (m->map[counter.x][counter.y] != '1')
				render_images(mlx, texture, "Floor.png", counter);
			if (m->map[counter.x][counter.y] == '1')
				render_images(mlx, texture, "Wall.png", counter);
			if (m->map[counter.x][counter.y] == 'E')
				render_images(mlx, texture, "Exit.png", counter);
			if (m->map[counter.x][counter.y] == 'P')
				player = render_player(mlx, texture, counter);
			if (m->map[counter.x][counter.y] == 'C')
				render_images(mlx, texture, "c_libft.png", counter);
			counter.y++;
		}
		counter.x++;
	}
	return (player);
}
