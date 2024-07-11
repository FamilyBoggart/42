/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:47:22 by alerome2          #+#    #+#             */
/*   Updated: 2024/07/11 15:42:13 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char 	*cut_line(char *buff)
{
	char	*line;
	int		i;
	int	len;

	len = 0;
	while (buff[len] != '\n' && buff[len] != '\0')
		len++;
	i = 0;
	line = malloc((len + 1) * sizeof(char));
	if (!line)
	{
		free(line);
		free(buff);
		return (NULL);
	}
	while (i <= len)
	{
		line[i] = buff[i];
		i++;
	}
	line[i] = '\0';
	return (line);
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
		br = read(fd, aux, BUFFER_SIZE);
		if(br <= 0)
			return (NULL);
		aux[br] = '\0';
		buff = ft_strjoin(buff, aux);
	}
	free(aux);
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

char	*get_next_line(int fd)
{
	static char	*buff;
	char*		line;

	if(fd < 0 && BUFFER_SIZE < 0)
		return (NULL);
	buff = reader(fd, buff);
	if(!buff)
		return (NULL);
	line = cut_line(buff);
	buff = new_line(buff);
	return (line);
}
