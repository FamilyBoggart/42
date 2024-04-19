/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 07:17:22 by alerome2          #+#    #+#             */
/*   Updated: 2024/04/15 17:20:45 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int n)
{
	if ((n >= 65 && n <= 90) || (n >= 97 && n <= 122))
		return (1);
	else
		return (0);
}
