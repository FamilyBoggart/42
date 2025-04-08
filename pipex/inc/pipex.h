/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:59:32 by alerome2          #+#    #+#             */
/*   Updated: 2025/04/08 18:22:01 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/inc/libft/libft.h"
#include "../libft/inc/printf/ft_printf.h"
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024
/**
 * @brief Estructura usada durante todo el proyecto
 * 
 * @param i			Contador auxiliar
 * @param cmd_size	Cantidad de comandos aplicados
 * @param envpaths	Array de las rutas Paths
 * @param cmd		Array del comando y las diferentes flags, separadas por espacio (Ej: "ls -l -a")
 * @param cmd_path	Ruta desde PATH para activar cada comando (Ej: "usr/bin/ls usr/sbin/find")
 * @param 
 */
typedef struct s_string
{
	int		i; //Contador (nº comandos)
	int		j; //Contador 2
	int		cmd_size; //Nº de comandos
	char	*input_file; //El nombre del archivo origen
	char	*output_file; //El nombre del archivo destino
	char	**envpaths; //Array para cada ruta path
	char	***cmd; // Array para cada comando con flags
	char	**cmd_path; // Ruta absoluta de cada comando
}	t_str;

char	*read_output(int fd);
void	finish(t_str *arguments, int ok);
void	ft_free(char **str);
void	command(t_str *arguments);
void	test_read(t_str *arguments);