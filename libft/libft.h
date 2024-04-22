/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:44:52 by alerome2          #+#    #+#             */
/*   Updated: 2024/04/22 20:59:24 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

//CHECKING

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);

// Comprueba si dos cadenas son iguales hasta un tamaño n
int				ft_strncmp(const char *s1, const char *s2, unsigned int n);
//CHARACTERS
int				ft_toupper(int c);
int				ft_tolower(int c);
//Comprueba el tamaño de un string
int				ft_strlen(const char *s);
// Asigna un carcter a un string hasta un tamaño n
void			*ft_memset(void *s, int c, unsigned long n);
void			*ft_bzero(void *s, unsigned long n);
//Copia un string src en un string dest
void			*ft_memcpy(void *dest, const void *src, unsigned int n);
void			*ft_memmove(void *dest, void *src, unsigned int n);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlcat(char *dst, const char *src, unsigned long dst_size);
char			*ft_strnstr(const char *big, const char *little, size_t len);
// Devuelve una subcadena dentro del string
char			*ft_substr(const char *s, unsigned int start, size_t len);
// Concatena las strings s1 y s2 mediante malloc
char			*ft_strjoin(const char *s1, const char *s2);
//FIND
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
//CONVERSION
int				ft_atoi(const char *str);
char			*ft_itoa(int n);

// ---------LEVEL 2---------
void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup(const char *s1);
