/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:56:30 by alerome2          #+#    #+#             */
/*   Updated: 2024/04/30 17:29:57 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
/*
#include <stdio.h>
void    read_content(t_list *lst)
{
    while (lst->next != NULL)
    {
        printf("%s\n",lst->content);
        lst = lst->next;
    }
    printf("%s\n",lst->content);  
}
int main ()
{

    t_list *head = NULL;

    t_list *newhead = malloc(sizeof(t_list));
    newhead->content = "Mundo";
    ft_lstadd_front(&head,newhead);
    read_content(head);
}
*/
