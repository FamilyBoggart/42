/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 19:43:33 by alerome2          #+#    #+#             */
/*   Updated: 2024/10/17 19:00:22 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**generate_map(void)
{
	t_counter	t;
	char		**map;

	map = malloc(sizeof(char *) * (HEIGHT / TS));
	if (!map)
		return (NULL);
	t.i = 0;
	t.a = 0;
	while (t.i < HEIGHT)
	{
		map[t.a] = malloc(sizeof(char) * WIDTH / TS);
		t.j = 0;
		t.b = 0;
		while (t.j < WIDTH)
		{
			if (t.j != 0 && t.j != WIDTH - TS && t.i != 0 && t.i != HEIGHT - TS)
				map[t.a][t.b++] = '0';
			else
				map[t.a][t.b++] = '1';
			t.j = t.j + TS;
		}
		t.a++;
		t.i = t.i + TS;
	}
	return (map);
}

void	show_map(char **map)
{
	int	i;
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
		write(1, "\n", 1);
		i++;
	}
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