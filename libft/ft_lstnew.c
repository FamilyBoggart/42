/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:04:36 by alerome2          #+#    #+#             */
/*   Updated: 2024/04/30 17:49:19 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*temp;

	temp = malloc(sizeof(t_list));
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
