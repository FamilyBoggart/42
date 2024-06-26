/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:49:50 by alerome2          #+#    #+#             */
/*   Updated: 2024/06/26 11:07:25 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# define BUFFER_SIZE 42

char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
/**
 * @brief  memcpy copies the string src in the string dest with n characters
 * 
 * @param dest 
 * @param src 
 * @param n 
 * @return void* 
 */
void	*ft_memcpy(void *dest, const void *src, unsigned int n);
/**
 * @brief strjoin concatenates string s1 to s2, being s1 the str's beggining
 * 
 * @param s1 
 * @param s2 
 * @return char* 
 */
char	*ft_strjoin(char *s1, char *s2);
/**
 * @brief The function returns the character c`s position in s
 * 
 * @param s 
 * @param c the character which we will find in s
 * @return char* 
 */
char	*ft_strchr(const char *s, int c);
#endif