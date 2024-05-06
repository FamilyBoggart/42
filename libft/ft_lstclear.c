/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:34:33 by alerome2          #+#    #+#             */
/*   Updated: 2024/05/06 15:23:29 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;

	if (!(*lst) || !del)
		return ;
	while (*lst)
	{
		aux = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		(*lst) = aux;
	}
}
/*
#include <stdio.h>
int main()
{
	 t_list *e1 = ft_lstnew("Lorem");
    t_list *e2 = ft_lstnew("ipsum");
    t_list *e3 = ft_lstnew("dolor");
    t_list *e4 = ft_lstnew("sit");
    e1->next = e2;
    e2->next = e3;
    e3->next = e4;
    e4->next = NULL;


}
*/
