/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 19:43:33 by alerome2          #+#    #+#             */
/*   Updated: 2024/11/04 14:27:25 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	init_render_map(void *mlx,t_textures *t, t_images *img, t_coords *m)
{
	mlx_image_t	*aux;
	int	i;
	
	img->map = malloc(sizeof(mlx_image_t *) * m->map_lines * m->map_columns);
	m->y = 0;
	i = 0;
	while (m->y < m->map_lines)
	{
		m->x = 0;
		while (m->x < m->map_columns)
		{
			if(m->map[m->y][m->x] == '1')
				aux = mlx_texture_to_image(mlx, t->wall);
			else
				aux = mlx_texture_to_image(mlx, t->floor);
			img->map[i] = aux;
			i++;
			mlx_image_to_window(mlx, aux, m->x * TS, m->y * TS);
			m->x++;
		}
		m->y++;
	}
}

void	init_collectibles(void *mlx, t_textures *t, t_images *img, t_coords *m)
{
	mlx_image_t	*aux;
	t_list		*list;
	
	img->collectibles = malloc(sizeof(t_list));
	img->collectibles->next = NULL;
	m->y = 0;
	ft_printf("(init_collectibles) Debug line 1\n");
	while (m->y < m->map_lines)
	{
		m->x = 0;
		while (m->x < m->map_columns)
		{
			if(m->map[m->y][m->x] == 'C')
			{
				aux = mlx_texture_to_image(mlx, t->collectible);
				mlx_image_to_window(mlx, aux, m->x * TS, m->y * TS);
				ft_printf("(init_collectibles) Debug line 2\n");
				list = ft_lstnew(aux);
				ft_lstadd_back(&img->collectibles, list);
				ft_printf("(init_collectibles) Debug line 3\n");
			}
			m->x++;
		}
		m->y++;
	}
}

void init_player_exit(void *mlx, t_textures *t, t_images *img, t_coords *m)
{
	mlx_image_t	*aux;
	
	m->y = 0;
	while (m->y < m->map_lines)
	{
		m->x = 0;
		while (m->x < m->map_columns)
		{
			if(m->map[m->y][m->x] == 'E')
			{
				aux = mlx_texture_to_image(mlx, t->exit);
				img->exit = aux;
				mlx_image_to_window(mlx, aux, m->x * TS, m->y * TS);
			}
			else if(m->map[m->y][m->x] == 'P')
			{
				aux = mlx_texture_to_image(mlx, t->p);
				m->player = aux;
				mlx_image_to_window(mlx, aux, m->x * TS, m->y * TS);
			}
			m->x++;
		}
		m->y++;
	}
}

void init_textures(t_textures *texture)
{
    char *path;
    char *full_path;
	
    path = "/home/usuario/Desktop/42/so_long/inc/Images/";
	
    full_path = ft_strjoin(path, "Wall.png");
    texture->wall = mlx_load_png(full_path);
    free(full_path);
	
    full_path = ft_strjoin(path, "Floor.png");
    texture->floor = mlx_load_png(full_path);
    free(full_path);
	
    full_path = ft_strjoin(path, "Exit.png");
    texture->exit = mlx_load_png(full_path);
    free(full_path);
	
    full_path = ft_strjoin(path, "Player.png");
    texture->p = mlx_load_png(full_path);
    free(full_path);
	
    full_path = ft_strjoin(path, "collectible.png");
    texture->collectible = mlx_load_png(full_path);
    free(full_path);
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

/**
 * @brief Primero renderiza las texturas de las celdas del mapa, luego renderiza la textura del jugador
 * 
 * @param m 
 * @param mlx 
 * @param texture 
 */
void render_map(t_coords *m, void *mlx, t_textures *texture)
{
	t_images *img;
	
	img = malloc(sizeof(t_images));
	init_textures(texture);
	init_render_map(mlx, texture, img, m);
	init_collectibles(mlx, texture, img, m);
	init_player_exit(mlx, texture, img, m);

	img->mlx = mlx;
	m->img_link = img;
	m->textures = texture;

}
