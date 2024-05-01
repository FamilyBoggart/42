/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:15:55 by alerome2          #+#    #+#             */
/*   Updated: 2024/05/01 13:31:31 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *l, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;

	newlist = malloc(sizeof(t_list));
	if (!newlist || !l || !f || !del)
		return (NULL);
	while (l->next != NULL)
	{
		newlist->content = f(l->content);
		newlist = l->next;
		del(l->content);
		l = l->next;
	}
	newlist->content = f(l->content);
	newlist = l->next;
	l = l->next;
	return (newlist);
}
/*
void  *f(void *content)
{
	return (content);
}
void del(void *content)
{
	if(!content)
		return ;
}
int main ()
{
	t_list *e1 = ft_lstnew("Lorem");
    t_list *e2 = ft_lstnew("ipsum");
    t_list *e3 = ft_lstnew("dolor");
    t_list *e4 = ft_lstnew("sit");
    e1->next = e2;
    e2->next = e3;
    e3->next = e4;
    e4->next = NULL;

	ft_lstmap(e1,&f,&del);
	return (0);
}
*/
