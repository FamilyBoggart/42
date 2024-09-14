/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:13:59 by alerome2          #+#    #+#             */
/*   Updated: 2024/09/14 13:09:20 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*fillarray(char **str, int size)
{
	int	*array;
	int	i;

	ft_printf("Size: %d\n", size);
	if (size == 0)
		array = malloc(sizeof(int) * 1);
	else
		array = malloc(sizeof(int) * size);
	if (!array)
	{
		free(array);
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		array[i] = ft_atoi(str[i]);
		//ft_printf("%d: %d\n",i,array[i]);
		i++;
	}
	return (array);
}

int	error_duplicated(int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	if (!array)
	{
		free(array);
		return (1);
	}
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j])
			{
				ft_printf("ERROR DE DUPLICIDAD (58)\n"); //Debug
				free(array);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	more_than_int(char **number)
{
	long int	n;
	int			i;

	i = 0;
	while (number[i])
	{
		n = ft_atol(number[i]);
		if (n > MAX_INT || n < MIN_INT)
		{
			ft_printf("NUMERO NO ENTERO (80)\n"); //Debug
			return (1);
		}
		i++;
	}
	return (0);
}

int	error_not_number(char **split)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (split[i])
	{
		j = 0;
		while (split[i][j])
		{
			c = split[i][j];
			if (!ft_isdigit(c) && c != '-' && c != '+')
			{
				ft_printf("NO ES UN NUMERO (103)\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	*check(char **str, int *argc)
{
	int	*array;
	int	size;

	size = (*argc) - 1;
	if (size == 1)
	{
		str = ft_split(str[0], ' ');
		size = ft_arraylen(str);
		(*argc) = size;
	}
	if (error_not_number(str) || more_than_int(str))
		return (NULL);
	array = fillarray(str, size);
	if (!array)
		return (NULL);
	if (error_duplicated(array, size))
		return (NULL);
	return (array);
}
