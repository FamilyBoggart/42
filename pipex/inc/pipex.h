/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:59:32 by alerome2          #+#    #+#             */
/*   Updated: 2024/12/10 12:58:48 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/inc/libft/libft.h"
#include "../libft/inc/printf/ft_printf.h"
#include <fcntl.h>

typedef struct s_string{
	char	**cmd;
	char	*envpath;
	char	**paths;
	char	**aux_path;
}	t_str;

void	ft_free(char **str);
void	command(char *argv[]);