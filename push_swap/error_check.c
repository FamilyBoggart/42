/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:13:59 by alerome2          #+#    #+#             */
/*   Updated: 2024/09/12 15:08:09 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_atol(const char *str)
{
	int			neg;
	int			i;
	long int	number;

	i = 0;
	neg = 0;
	number = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		neg = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i] - '0');
		i++;
	}
	if (neg == 1)
		return (-number);
	else
		return (number);
}

int	error_duplicated(int *array)
{
	int	i;
	int	j;

	i = 0;
	while (array[i])
	{
		j = i + 1;
		while (array[j])
		{
			if (array[i] == array[j])
			{
				free(array);
				ft_printf("Error\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	more_than_int(char *number)
{
	long int	n;

	n = ft_atol(number);
	if (n > MAX_INT || n < MIN_INT)
	{
		ft_printf("Error\n");
		return (1);
	}
	return (0);
}

int	error_not_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			ft_printf("Error\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	check(char **str, int *array)
{
	int	i;

	if (!array)
	{
		free(array);
		return (1);
	}
	i = 1;
	while (str[i])
	{
		if (error_not_number(str[i]) || more_than_int(str[i]))
		{
			free(array);
			return (1);
		}
		i++;
	}
	return (0);
}
