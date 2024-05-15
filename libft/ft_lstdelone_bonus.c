/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:44:28 by alerome2          #+#    #+#             */
/*   Updated: 2024/05/14 20:10:58 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free (lst);
}

/*
#include <stdlib.h>
#include <stdio.h>

void	ft_del( void	*content)
{
	free(content);
}

t_list  *ft_lstnew(void *content)
{
    t_list  *temp;

    temp = malloc(sizeof(t_list));
    temp->content = content;
    temp->next = NULL;
    return (temp);
}

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

	ft_lstdelone(e3,&ft_del);
	if(e1)
		printf("Contenido e1: %s\n",e1->content);
	if(e2)
		printf("Contenido e2: %s\n",e2->content);
	if(e3)
		printf("Contenido e3: %s\n",e3->content);
	if(e4)
		printf("Contenido e4: %s\n",e4->content);

}
*/
