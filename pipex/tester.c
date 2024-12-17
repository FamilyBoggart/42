/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:45:17 by alerome2          #+#    #+#             */
/*   Updated: 2024/12/17 13:53:52 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/pipex.h"

void check(void)
{
	return;
}
int main(void)
{
	write(1, "\033[34m[1]. /pipex\n\033[0m", 22);
	system ("./pipex");
	check();
	write(1, "[\033[34m2]. /pipex testfile.txt ls cat :\n\033[0m", 44);
	system ("./pipex testfile.txt ls cat");
	check();
	write(1, "\033[34m[3]. /pipex testfile1.txt ls cat outfile.txt:\n\033[0m", 56);
	system ("./pipex testfile1.txt ls cat outfile.txt");
	check();
	// [4.] REPEAT COMMANDS
	ft_printf("\033[34m[4]. /pipex testfile1.txt ls cat grep find find outfile.txt:\n\033[0m");
	system ("./pipex testfile1.txt ls cat grep find find outfile.txt");
	check();
	// [5.] EVERY COMMAND IS THE SAME
	ft_printf("\033[34m[5]. /pipex testfile1.txt ls ls ls ls ls outfile.txt:\n\033[0m");
	system ("./pipex testfile1.txt ls ls ls ls ls outfile.txt");
	check();
	// [6.] ERROR. COMMAND NOT FOUND
	ft_printf("\033[34m[6]. /pipex testfile1.txt ls cato outfile.txt:\n\033[0m");
	system ("./pipex testfile1.txt ls cato outfile.txt");
	check();
	return (0);
}