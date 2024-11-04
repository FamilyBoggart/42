/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:41:23 by alerome2          #+#    #+#             */
/*   Updated: 2024/11/02 16:36:47 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"


int count_colectibles(t_coords *m)
{
	int	i;
	int	j;
	int	count;
	char **map;

	map = m->map;
	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	m->total_collectibles = count;
	m->collected = 0;
	return (count);
}

void collect(t_coords *m)
{
	int	x;
	int	y;
	char **map;


	map = m->map;
	x = m->player->instances[0].x / TS;
	y = m->player->instances[0].y / TS;
	if (map[y][x] == 'C')
	{
		map[y][x] = '0';
		m->collected++;
		ft_printf("\033[93m (collectibles.c) Collectibles: %d/%d\n\033[0m", m->collected, m->total_collectibles);
	}
}
