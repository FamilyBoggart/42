/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:28:24 by alerome2          #+#    #+#             */
/*   Updated: 2024/07/20 13:51:12 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//valgrind --leak-check=full ./a.out;
#include "../inc/get_next_line/get_next_line.h"
#include "../inc/printf/ft_printf.h"

int	main(void)
{
	int		fd;
	char	*line;
	int		cont;

	line = NULL;
	cont = 0;
	fd = open("/home/usuario/Desktop/42/libft/inc/get_next_line/test.txt", O_RDONLY);
	line = get_next_line(fd);
	while ((line))
	{
		ft_printf("%d: %s", cont++, line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (0);
}
