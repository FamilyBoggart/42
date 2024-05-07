/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:44:52 by alerome2          #+#    #+#             */
/*   Updated: 2024/05/01 22:45:57 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// COUNTERS
typedef struct contador
{
	int	i;
	int	j;
	int	k;
	int	len;
	int	size;
}	t_counter;

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
// Encuentra un caracter c, en la cadena s y devuelve el byte donde se encuentra
void			*ft_memchr(const void *s, int c, unsigned long n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlcat(char *dst, const char *src, unsigned long dst_size);
char			*ft_strnstr(const char *big, const char *little, size_t len);
// Devuelve una subcadena dentro del string
char			*ft_substr(const char *s, unsigned int start, size_t len);
// Concatena las strings s1 y s2 mediante malloc
char			*ft_strjoin(const char *s1, const char *s2);
// Elimina de la cadena s1, los caracteres del string set
char			*ft_strtrim(const char *s1, const char *set);
/*
*   ft_split split the string ins subtrstrings divides each char c
*/
char			**ft_split(const char *s, char c);
//--------------
//FIND
//-------------
/*
 * ft_strchr find the first occurence of character c in the string s
 */
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
//CONVERSION
int				ft_atoi(const char *str);
char			*ft_itoa(int n);
//FUNCION COMO ARGUMENTOS
char			*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char			*ft_striteri(char *s, void (*f)(unsigned int, char *));

// FILE DESCRIPTORS
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
// ---------LEVEL 2---------
void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup(const char *s1);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

// Crea un nuevo nodo con el contenido dado
t_list			*ft_lstnew(void *content);
// Añade el nuevo nodo 'new' al principio de la lista 'lst'
void			ft_lstadd_front(t_list	**lst, t_list *new);
//Obtiene el tamaño de la cadena desde el primer nodo de la lista 'lst'
int				ft_lstsize(t_list *lst);
//Devuelve el ultimo nodo de la lista recibiendo el primer nodo 'lst'
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new); //Falta un poco
// lstdelone borra el nodo de en medio y conecta el anterior y siguiente
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *l, void *(*f)(void *), void (*del)(void *));
