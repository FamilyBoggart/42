/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:59:32 by alerome2          #+#    #+#             */
/*   Updated: 2024/12/11 11:57:16 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/inc/libft/libft.h"
#include "../libft/inc/printf/ft_printf.h"
#include <fcntl.h>

/**
 * @brief Estructura usada durante todo el proyecto
 * 
 * @param i			Contador auxiliar
 * @param cmd_size	Cantidad de comandos aplicados
 * @param envpath	Variable PATH
 * @param paths		Array de las diferentes rutas de variables de PATH
 * @param cmd		Array del comando y las diferentes flags, separadas por espacio (Ej: "ls -l -a")
 * @param cmd_path	Ruta desde PATH para activar cada comando (Ej: "usr/bin/ls usr/sbin/find")
 * @param 
 */
typedef struct s_string{
	int		i;
	int		cmd_size;
	char	*envpath;
	char	**paths;
	char	**cmd;
	char	**cmd_path;

	char	**aux_path;
}	t_str;

void	ft_free(char **str);
void	command(char *argv[]);