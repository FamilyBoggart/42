/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:09:36 by alerome2          #+#    #+#             */
/*   Updated: 2024/05/14 20:09:04 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	neg;
	int	i;
	int	number;

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
/*
#include <stdlib.h>
#include <stdio.h>
int main (void)
{
	char *s1 = "	-46yugyg5d6";
	printf("atoi: %d\n",atoi(s1));
	printf("ft_ atoi: %d",ft_atoi(s1));
	return 0;

}
*/
