/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:18:41 by alerome2          #+#    #+#             */
/*   Updated: 2024/11/04 12:31:18 by alerome2         ###   ########.fr       */
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
			{
				ft_printf("(erase_collectible) Debug line 1\n");
				mlx_delete_image(map->img_link->mlx, image);
			}
			aux = aux->next;
		}
		ft_printf("(erase_collectible) Collectible: %p\n",image); // Debug
		
	}
}
