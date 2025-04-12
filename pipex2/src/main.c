/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 18:41:37 by alerome2          #+#    #+#             */
/*   Updated: 2025/04/12 20:59:20 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(int argc, char	*argv[])
{
	t_str	*args;

	if (argc < 5)
	{
		ft_printf("Error\n");
		return (1);
	}
	args = check(argc, argv);
	if (args)
		ft_free(args);
	else
		ft_printf("Error\n");
	return (0);
}
