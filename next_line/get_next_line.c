/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:47:22 by alerome2          #+#    #+#             */
/*   Updated: 2024/07/11 11:45:16 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char 	*cut_line(char *buff, int len)
{
	char	*line;
	int		i;

	i = 0;
	line = malloc((len + 1) * sizeof(char));
	if (!line)
	{
		free(line);
		free(buff);
		return (NULL);
	}
	while (i < len)
	{
		line[i] = buff[i];
		i++;
	}
	line[i] = '\n';
	return (line);
}
int divide_line(char *buff)
{
	int i;

	i = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
		i++;
	return (i);
}

static char	*reader(int fd, char *buff)
{
	int		br;
	char	*aux;

	aux = malloc ((BUFFER_SIZE + 1) * sizeof(char));
	if (!aux)
	{
		free(aux);
		free(buff);
		return (NULL);
	}
	br = 1;
	while (!ft_strchr(aux, '\n') && br != 0)
	{
		if (br == -1)
			return (NULL);
		br = read(fd, aux, BUFFER_SIZE);
		aux[br] = '\0';
		buff = ft_strjoin(buff, aux);
	}
	return (buff);
}
char	*new_line(char *buff)
{
	int		i;
	char	*aux;

	i = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
		i++;
	aux = ft_substr(buff, i + 1, ft_strlen(buff) - i);
	return (aux);
}

/**
 * @brief Get the next line object
 * 
 * @param fd 
 * @return char* 
 */
char	*get_next_line(int fd)
{
	static char	*buff;
	char*		line;
	//char*		aux;

	buff = reader(fd, buff);
	line = cut_line(buff, divide_line(buff));
	buff = new_line(buff);
	return (line);
}
