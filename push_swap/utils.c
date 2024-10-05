/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 09:53:56 by alerome2          #+#    #+#             */
/*   Updated: 2024/10/05 09:44:34 by alerome2         ###   ########.fr       */
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

void	show(t_list *a, t_list *sb)
{
	ft_printf("\nStack a\n--------\n");
	while (a)
	{
		ft_printf("%d:\tpos: %d\tweight_a: %d\tdirection: %d\tweight_b: %d\t"
			"direction: %d\ttotal_weight: %d\n",
			((t_stack *)a->content)->value, ((t_stack *)a->content)->pos,
			((t_stack *)a->content)->moves[0],
			((t_stack *)a->content)->moves[1],
			((t_stack *)a->content)->moves[2],
			((t_stack *)a->content)->moves[3], ((t_stack *)a->content)->weight);
		a = a->next;
	}
	ft_printf("Stack b\n--------\n");
	while (sb)
	{
		ft_printf("%d:\tpos: %d\tweight_a: %d\tdirection: %d\tweight_b: %d\t"
			"direction: %d\ttotal_weight: %d\n",
			((t_stack *)sb->content)->value, ((t_stack *)sb->content)->pos,
			((t_stack *)sb->content)->moves[0],
			((t_stack *)sb->content)->moves[1],
			((t_stack *)sb->content)->moves[2],
			((t_stack *)sb->content)->moves[3],
			((t_stack *)sb->content)->weight);
		sb = sb->next;
	}
}
