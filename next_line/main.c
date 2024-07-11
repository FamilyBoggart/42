/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:28:24 by alerome2          #+#    #+#             */
/*   Updated: 2024/07/11 15:13:46 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
int main (void){
	int		fd;
	char	*line = NULL;
	int		cont;

	cont = 0;
	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	while ((line))
	{
		printf("%d: %s",cont++, line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);


//valgrind --leak-check=full ./a.out;
	return 0;

	
}