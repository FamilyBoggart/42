/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:28:24 by alerome2          #+#    #+#             */
/*   Updated: 2024/07/13 12:13:26 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//valgrind --leak-check=full ./a.out;
#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;
	int		cont;

	line = NULL;
	cont = 0;
	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	while ((line))
	{
		printf("%d: %s", cont++, line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (0);
}
