/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 09:53:56 by alerome2          #+#    #+#             */
/*   Updated: 2024/09/21 12:46:25 by alerome2         ###   ########.fr       */
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

int	ft_arraylen(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

char	**refill_split(char **split)
{
	int		i;
	char	**newsplit;

	i = 1;
	newsplit = malloc(sizeof(char *) * ft_arraylen(split));
	while (split[i])
	{
		newsplit[i - 1] = split[i];
		i++;
	}
	newsplit[i] = NULL;
	return (newsplit);
}

int	closefile(int fd, char*line)
{
	free(line);
	close(fd);
	return (0);
}
