/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:45:17 by alerome2          #+#    #+#             */
/*   Updated: 2024/12/17 13:32:42 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/pipex.h"

int main(void)
{
	system ("make debug");
	write(1, "\033[34m[1]. /pipex\n\033[0m", 22);
	system ("./pipex");
	write(1, "[\033[34m2]. /pipex testfile.txt ls cat :\n\033[0m", 44);
	system ("./pipex testfile.txt ls cat");
	write(1, "\033[34m[3]. /pipex testfile.txt ls cat outfile.txt:\n\033[0m", 55);
	system ("./pipex testfile1.txt ls cat outfile.txt");
	return (0);
}