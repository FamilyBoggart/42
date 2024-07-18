/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:04:36 by alerome2          #+#    #+#             */
/*   Updated: 2024/07/18 20:07:31 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*temp;

	temp = malloc(sizeof(t_list));
	if (!temp)
		return (NULL);
	temp->content = content;
	temp->next = NULL;
	return (temp);
}
/*
#include <stdio.h>
int main()
{
t_list *prueba=malloc(sizeof(t_list));
char *string = "Hola mundo";
prueba = ft_lstnew(string);
printf("Contenido: %s",prueba->content);
 return 0;    
}
*/
