/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:15:55 by alerome2          #+#    #+#             */
/*   Updated: 2024/05/14 20:11:09 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *l, void *(*f)(void *), void (*del)(void *))
{
	t_list	*pointer;
	t_list	*newlist;

	if (!l)
		return (NULL);
	pointer = NULL;
	while (l != NULL)
	{
		newlist = ft_lstnew(f(l->content));
		if (!newlist)
		{
			ft_lstclear(&pointer, del);
			return (NULL);
		}
		ft_lstadd_back(&pointer, newlist);
		l = l->next;
	}
	return (pointer);
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
