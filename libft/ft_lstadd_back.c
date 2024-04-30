/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:11:48 by alerome2          #+#    #+#             */
/*   Updated: 2024/04/30 19:08:31 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	else
	{
		temp = ft_lstlast(*lst);
		temp->next = new;
		new->next = NULL;
	}
}
/*
#include <stdio.h>
#include <stdlib.h>
int main()
{
	t_list	*head = NULL;

	t_list	*o1=malloc(sizeof(t_list));
	o1->content="Hola";
	o1->next = NULL;

	ft_lstadd_back(&head,o1);
	printf("Nodos: %d\n", ft_lstsize(o1));

	t_list  *o2=malloc(sizeof(t_list));
    o1->content="Mundo";
    o2->next = NULL;

    ft_lstadd_back(&head,o2);
    printf("Nodos: %d\n", ft_lstsize(o1));
}
*/
