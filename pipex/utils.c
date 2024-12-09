/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:13:35 by alerome2          #+#    #+#             */
/*   Updated: 2024/12/09 12:00:43 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/pipex.h"

void	ft_free(char **str)
{
	int	i;
	
	i = 0;
	if(!str)
		return;
	if (!*str && str)
	{
		free(str);
		return;
	}
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	if(*str && str)
		free(str);
	else
		ft_printf("ERROR DE LIBERACION DE MEMORIA\n");
}
