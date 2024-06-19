/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:47:22 by alerome2          #+#    #+#             */
/*   Updated: 2024/06/19 12:44:28 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

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

/**
 * @brief Get the next line object
 * 
 * @param fd 
 * @return char* 
 */
char	*get_next_line(int fd)
{
	static char	*buff;

	buff = reader(fd, buff);
	printf("%s", buff);
	free(buff);
	return (buff);
}
// PSEUDOCODE
/*
	1. EL ARCHIVO SE ABRE EN MAIN, EL FILE DESCRIPTOR SE LE PASA COMO ARGUMENTO
	A NUESTRO GET_NEXT_LINE
	
	2. GNL TIENE QUE LEER EL ARCHIVO, ASI QUE HAY QUE HACER COMPROBACIONES DE
	ERRORES

	3. EL ARCHIVO DEBE LEERSE LINEA POR LINEA, ES DECIR, DEBEMOS USAR UN ARRAY
	EN DONDE INTRODUCIR LOS DATOS ENCONTRADOS HASTA QUE ENCONTREMOS UN \n 

	4. USAREMOS UNA FUNCION READER PARA LEER UN ARCHIVO HASTA ENCONTRAR \n o \0
	
	5. CUANDO ENCONTRAMOS UN \n LANZAMOS TODO EL BUFFER LEIDO A NUESTRA VARIABLE
	ESTATICA EXTERNA
	
*/