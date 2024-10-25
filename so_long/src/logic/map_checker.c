/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:37:38 by alerome2          #+#    #+#             */
/*   Updated: 2024/10/25 13:43:02 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_chars(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'P' && \
			map[i][j] != 'E' && map[i][j] != 'C')
			{
				if (!(map[i][j] == '\n' && map[i][j + 1] == 0))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_rectangular(char **map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = ft_strlen(map[0]) - 1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (map[i][j - 1] == '\n')
			j--;
		if (j != len)
			return (0);
		i++;
	}
	return (1);
}

int	check_borders(char **map)
{
	int	i;
	int	j;
	int	len;
	int	row;

	i = 0;
	len = ft_strlen(map[0]) - 2;
	row = rows(map);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '\n' && map[i][j + 1] == 0)
				j++;
			else if (i == 0 || i == row - 1 || j == 0 || j == len)
			{
				if (map[i][j] != '1')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_map(char **map)
{
	if (!check_chars(map))
	{
		ft_printf("(check_map)Error: Invalid characters in map\n");
		return (0);
	}
	if (!check_rectangular(map))
	{
		ft_printf("(check_map)Error: Map is not rectangular\n");
		return (0);
	}
	if (!check_borders(map))
	{
		ft_printf("(check_map)Error: Borders are open\n");
		return (0);
	}
	if (!only_one_player_and_exit(map))
	{
		ft_printf("(check_map)Error: Only one player and one exit allowed\n");
		return (0);
	}
	return (1);
}
