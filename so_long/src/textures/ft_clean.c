/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:31:24 by alerome2          #+#    #+#             */
/*   Updated: 2024/11/11 15:11:33 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	ft_check_textures(t_textures *textures)
{
	if (!textures->collectible)
	{
		ft_printf("Error loading textures\n");
		exit(EXIT_FAILURE);
	}
	if (!textures->exit)
	{
		ft_printf("Error loading textures\n");
		exit(EXIT_FAILURE);
	}
	if (!textures->floor)
	{
		ft_printf("Error loading textures\n");
		exit(EXIT_FAILURE);
	}
	if (!textures->wall)
	{
		ft_printf("Error loading textures\n");
		exit(EXIT_FAILURE);
	}
}

void	ft_clean_textures(t_textures *texture)
{
	mlx_delete_texture(texture->collectible);
	mlx_delete_texture(texture->exit);
	mlx_delete_texture(texture->floor);
	mlx_delete_texture(texture->wall);
	mlx_delete_texture(texture->p);
}
