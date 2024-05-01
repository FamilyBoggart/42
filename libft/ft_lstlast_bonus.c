/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:43:58 by alerome2          #+#    #+#             */
/*   Updated: 2024/04/30 19:07:54 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	if (!temp)
		return (NULL);
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}
/*
#include <stdlib.h>
#include <stdio.h>
int main(void)
{
	t_list *head = malloc(sizeof(t_list));
	head->content= "Hola";
	head->next = NULL;

	t_list *o2 = malloc(sizeof(t_list));
	o2->content = "Mundo";
	o2->next = NULL;
	head->next = o2;

	t_list *o3 = malloc(sizeof(t_list));
	o3->content = "Bonito";
	o3->next = NULL;
	o2->next= o3;

	printf("Contenido del ultimo nodo: %s\n",ft_lstlast(head)->content);
	if(!ft_lstlast(head)->next)
		printf("El puntero apunta a NULL");
	return 0;
}
*/
