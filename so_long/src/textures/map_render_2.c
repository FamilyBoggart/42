/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:10:29 by alerome2          #+#    #+#             */
/*   Updated: 2024/11/12 12:15:51 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	init_render_player( t_coords *m, t_textures *t)
{
	m->y = 0;
	while (m->y < m->map_lines)
	{
		m->x = 0;
		while (m->x < m->map_columns)
		{
			if (m->map[m->y][m->x] == 'P')
				render_sprite(m, t->p);
			m->x++;
		}
		m->y++;
	}
}
