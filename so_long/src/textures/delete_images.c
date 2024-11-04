/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:18:41 by alerome2          #+#    #+#             */
/*   Updated: 2024/11/04 14:07:07 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void erase_collectible(t_coords *map)
{
	mlx_image_t	*image;
	t_list		*aux;
	
	aux =  map->img_link->collectibles->next;
	while(aux)
	{
		image = aux->content;
		if (!image)
			aux = aux->next;
		else
		{
			if((image->instances[0].x == map->player->instances[0].x ) &&
			image->instances[0].y == map->player->instances[0].y)
				mlx_delete_image(map->img_link->mlx, image);
			aux = aux->next;
			ft_printf("(erase_collectible) Collectible: %p\n",image); // Debug
		}
		
	}
}

void free_collectibles(t_list *l, void *mlx)
{
	t_list	*aux;

	//Free linked List
	if (!l)
		return ;
	while (l)
	{
		ft_printf("(free_collectibles) Debug line 1\n");
		if(l->content)
		{
			ft_printf("(free_collectibles) Debug line 2\n");
			mlx_delete_image(mlx, l->content);
		}
		aux = l->next;
		free(l);
		l = aux;
	}
	if(!aux && !l)
		ft_printf("\033[32m(free_collectibles) Debug line 3. OK\033[0m\n");
}
void free_map_images(mlx_image_t **map, void *mlx)
{
	int	i;

	i = 0;
	while (map[i])
	{
		mlx_delete_image(mlx, map[i]);
		i++;
	}
	if(!map[i])
		ft_printf("\033[32m(free_map_images) Debug line 1. OK\033[0m\n");
}
void	free_all(t_coords *map)
{
	t_images *img;
	void *mlx;

	img = map->img_link;
	mlx = map->img_link->mlx;
	ft_printf("(free_all) Debug line 1\n");
	free_collectibles(img->collectibles, map->img_link->mlx);
	ft_printf("(free_all) Debug line 2\n");
	mlx_delete_image(img->mlx, img->exit);
	ft_printf("(free_all) Debug line 3\n");
	free_map_images(img->map, img->mlx);
	ft_printf("(free_all) Debug line 5\n");
	free(img->map);
	ft_printf("(free_all) Debug line 6\n");
	free(img);
	ft_printf("(free_all) Debug line 7\n");
	mlx_delete_image(mlx, map->player);
	ft_printf("(free_all) Debug line 8\n");
	free_map(map->map);
	ft_printf("(free_all) Debug line 11\n");
	mlx_delete_texture(map->textures->wall);
	mlx_delete_texture(map->textures->floor);
	mlx_delete_texture(map->textures->exit);
	mlx_delete_texture(map->textures->p);
	mlx_delete_texture(map->textures->collectible);
	free(map->textures);
	ft_printf("(free_all) Debug line 12\n");
	free(map);
}
