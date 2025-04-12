/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 20:22:01 by alerome2          #+#    #+#             */
/*   Updated: 2025/04/12 21:19:40 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	cmd_free(char	***cmd)
{
	int	i;
	int	j;

	i = 0;
	if (!cmd)
		return ;
	while ((*cmd)[i])
	{
		j = 0;
		while ((*cmd)[i][j])
			j++;
		while (--j >= 0)
			free((*cmd)[i][j--]);
		i++;
	}
	while (--i >= 0)
		free((*cmd)[i--]);
	free(*cmd);
	free(cmd);
}

void	ft_free(t_str *args)
{
	if (!args)
		return ;
	if (args->cmd)
		cmd_free(args->cmd);
	free(args);
}
