/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 11:31:29 by alerome2          #+#    #+#             */
/*   Updated: 2024/07/20 17:14:21 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int	*array;
	int	i;

	i = 1;
	array = malloc(argc * sizeof(int));
	if (argc < 2 || !array)
	{
		ft_printf("Error");
		return (0);
	}
	while (argv[i])
	{
		array[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	array[i] = '\0';
	return (0);
}
