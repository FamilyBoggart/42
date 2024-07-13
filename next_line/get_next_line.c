/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:47:22 by alerome2          #+#    #+#             */
/*   Updated: 2024/07/13 12:11:22 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*cut_line(char *buff)
{
	int		i;
	char	*aux;

	i = 0;
	if (!*buff)
		return (NULL);
	while (buff[i] && buff[i] != '\n')
		i++;
	aux = malloc(i + 2);
	if (!aux)
		return (NULL);
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		aux[i] = buff[i];
		i++;
	}
	if (buff[i] == '\n')
	{
		aux[i] = buff[i];
		i++;
	}
	aux[i] = 0;
	return (aux);
}

static char	*reader(int fd, char *buff)
{
	int		br;
	char	*aux;

	aux = malloc ((BUFFER_SIZE + 1) * sizeof(char));
	if (!aux)
		return (NULL);
	br = 1;
	while (!ft_strchr(buff, '\n') && br != 0)
	{
		br = read(fd, aux, BUFFER_SIZE);
		if (br == -1)
		{
			free(aux);
			free(buff);
			return (NULL);
		}
		aux[br] = '\0';
		buff = ft_strjoin(buff, aux);
	}
	free(aux);
	return (buff);
}

char	*new_line(char *buff)
{
	int		i;
	int		j;
	char	*aux;

	i = 0;
	j = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	aux = malloc(ft_strlen(buff) - i + 1);
	if (!aux)
		return (NULL);
	i++;
	while (buff[i])
		aux[j++] = buff[i++];
	aux[j] = 0;
	free(buff);
	return (aux);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;

	if (fd < 0 && BUFFER_SIZE < 0)
		return (NULL);
	buff = reader(fd, buff);
	if (!buff)
		return (NULL);
	line = cut_line(buff);
	buff = new_line(buff);
	return (line);
}
