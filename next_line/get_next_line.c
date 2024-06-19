/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:47:22 by alerome2          #+#    #+#             */
/*   Updated: 2024/06/19 11:07:30 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/**
 * @brief Get the next line object
 * 
 * @param fd 
 * @return char* 
 */
char	*get_next_line(int fd)
{
	char	*str;
	int		br;

	str = malloc (BUFFER_SIZE * sizeof(char));
	if (!str)
		return (NULL);
	br = read(fd, str, BUFFER_SIZE);
	printf("br: %d", br);
	if (br == -1)
		return (NULL);
	printf("%s", str);
	while (br != 0)
	{
		br = read(fd, str, BUFFER_SIZE);
		printf("%s", str);
	}
	free(str);
	return (str);
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