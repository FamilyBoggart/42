/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:18:41 by alerome2          #+#    #+#             */
/*   Updated: 2024/11/11 15:05:23 by alerome2         ###   ########.fr       */
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
	free(map);
}

void	erase_collectible(t_coords *map)
{
	mlx_image_t	*image;
	t_list		*aux;

	aux = map->img_link->collectibles->next;
	while (aux)
	{
		image = aux->content;
		if (!image)
			aux = aux->next;
		else
		{
			if ((image->instances[0].x == map->player->instances[0].x)
				&& image->instances[0].y == map->player->instances[0].y)
				image->enabled = 0;
			aux = aux->next;
		}
	}
}

void	free_collectibles(t_list *l, void *mlx)
{
	t_list	*aux;

	if (!l)
		return ;
	while (l)
	{
		if (l->content)
			mlx_delete_image(mlx, l->content);
		aux = l->next;
		free(l);
		l = aux;
	}
	if (!aux && !l)
		ft_printf("\033[32m(free_collectibles) Linked list freed\033[0m\n");
}

void	free_map_images(mlx_image_t **map, void *mlx)
{
	int	i;

	i = 0;
	while (map[i])
	{
		mlx_delete_image(mlx, map[i]);
		i++;
	}
	if (!map[i])
		ft_printf("\033[32m(free_map_images) Images Freed\033[0m\n");
}

void	free_all(t_coords *map)
{
	t_images	*img;
	void		*mlx;

	img = map->img_link;
	mlx = map->img_link->mlx;
	free_collectibles(img->collectibles, map->img_link->mlx);
	mlx_delete_image(img->mlx, img->exit);
	free_map_images(img->map, img->mlx);
	free(img->map);
	free(img);
	mlx_delete_image(mlx, map->player);
	free_map(map->map);
	free(map);
}
