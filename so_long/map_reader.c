/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:42:56 by alerome2          #+#    #+#             */
/*   Updated: 2024/10/18 11:52:24 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_ber(char *arg)
{
	char	*aux;

	aux = arg;
	while (*aux)
		aux++;
	while (arg < aux)
	{
		if (*aux == '.')
		{
			if (*(aux - 1) == 'r' && *(aux - 2) == 'e' && *(aux - 3) == 'b')
				return (1);
		}
		aux--;
	}
	return (0);
}

char	**generate_map(char *arg)
{
	char	**map;

	map = NULL;
	if (!check_ber(arg))
		return (NULL);
	map = read_map(arg);
	if (!map || !check_map(map))
		return (NULL);
	return (map);
}
