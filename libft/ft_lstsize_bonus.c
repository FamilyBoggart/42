/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:20:49 by alerome2          #+#    #+#             */
/*   Updated: 2024/04/30 19:07:24 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	counter;

	counter = 0;
	if (lst == NULL)
		return (counter);
	while (lst->next != NULL)
	{
		counter++;
		lst = lst->next;
	}
	return (counter + 1);
}
/*
#include <stdio.h>
int main(void)
{
	t_list *head = NULL;

	t_list *o2=malloc(sizeof(t_list));
	o2->content = "Mundo";
	o2->next = NULL;
	head = o2;

	t_list *o3=malloc(sizeof(t_list));
	o3->content = "Bonito";
	o3->next = NULL;
	o2->next = o3;

	printf("Nº de nodos %d",ft_lstsize(head));
	return 0;
}
*/
