/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 18:42:17 by alerome2          #+#    #+#             */
/*   Updated: 2025/04/12 20:52:50 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"
#include "./libft.h"

typedef struct s_string
{
	int		cmd_size;
	char	*input_file;
	char	*output_file;
	char	**envpaths;
	char	***cmd;
}	t_str;

t_str	*check(int argc, char **argv);
void	ft_free(t_str *args);