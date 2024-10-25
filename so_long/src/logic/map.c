/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 19:43:33 by alerome2          #+#    #+#             */
/*   Updated: 2024/10/25 17:58:56 by alerome2         ###   ########.fr       */
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
	t.k = 0;
	while (t.i < HEIGHT)
	{
		map[t.k] = malloc(sizeof(char) * WIDTH / TS);
		t.j = 0;
		t.size = 0;
		while (t.j < WIDTH)
		{
			if (t.j != 0 && t.j != WIDTH - TS && t.i != 0 && t.i != HEIGHT - TS)
				map[t.k][t.size++] = '0';
			else
				map[t.k][t.size++] = '1';
			t.j = t.j + TS;
		}
		t.k++;
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
		i++;
	}
	write(1, "\n", 1);
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

int	rows(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	render_map(void *mlx, t_textures *texture, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i][j])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
			{
				texture->wall = mlx_load_png("./includes/Wall.png");
				mlx_image_to_window(mlx, texture->wall, j * 100, i * 100);
			}
			else
			{
				texture->floor = mlx_load_png("./includes/Floor.png");
				mlx_image_to_window(mlx, texture->floor, j * 100, i * 100);
			}
			j++;
		}
		i++;
	}
}
