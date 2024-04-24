/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:52:39 by alerome2          #+#    #+#             */
/*   Updated: 2024/04/24 10:58:00 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "libft.h"

void ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s,fd);
	write(fd,"\n",1);
}
