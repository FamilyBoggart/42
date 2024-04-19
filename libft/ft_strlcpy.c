/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:03:57 by alerome2          #+#    #+#             */
/*   Updated: 2024/04/19 17:28:56 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*strlcpy(char *dst, const char *src, long dstsize)
{
	char		*aux_src;
	char		*aux_dest;
	long		i;

	aux_src = (char *)src;
	aux_dest = (char *)dst;
	i = 0;

	if(dstsize <= 0 || !aux_src || !aux_dest)
	while (i < (dstsize -1))
	{
		i++;
		aux_dest[i] = aux_src[i];
	}
	
}
