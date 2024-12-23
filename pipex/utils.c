/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:13:35 by alerome2          #+#    #+#             */
/*   Updated: 2024/12/23 17:24:03 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/pipex.h"

char*	read_output(int fd)
{
	int		br;
	int		chars;
	char	*buf;
	int		buf_size;
	char	*aux;

	buf_size = BUFFER_SIZE;
	buf = malloc(buf_size);
	aux = malloc(1);
	br = read(fd, aux, 1);
	chars = 0;
	while (br > 0)
	{
		if (chars == buf_size)
		{
			buf_size += BUFFER_SIZE;
			buf = realloc(buf, buf_size);
		}
		buf[chars] = *aux;
		br = read(fd, aux, 1);
		chars++;
	}
	free(aux);
	buf[chars] = '\0';
	return (buf);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	if (*str && str)
		free(str);
	else
		ft_printf("ERROR DE LIBERACION DE MEMORIA\n");
}

void	finish(t_str *str, int ok)
{
	if (ok == 1)
	{
		str->cmd[str->i] = NULL;
		str->cmd_path[str->i] = NULL;
	}
	ft_free(str->cmd);
	ft_free(str->cmd_path);
}
