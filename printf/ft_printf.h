/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:14:48 by alerome2          #+#    #+#             */
/*   Updated: 2024/05/23 12:21:53 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# define MAX_UINT 4294967295
/**
 * @brief The main function. Emulate printf function
 * 
 * @param str Text which will be analyzed and printed
 * @param ... Variable arguments
 * @return int 
 */
int	ft_printf(const char *str,...);
/**
 * @brief This function writes a character
 * 
 * @param c The character which will we written
 * @return int 
 */
int	ft_putchar(char c);
/**
 * @brief This function writes a number
 * 
 * @param n The number which will be written
 * @return int 
 */
int	ft_putnbr(int n);
/**
 * @brief This function writes a string
 * 
 * @param str Thw string which will be written
 * @return int 
 */
int	ft_putstr(char *str);
/**
 * @brief This function works as ft_putnbr but is used for unsigned integers
 * 
 * @param n The number which will be written, in unsigned range
 * @return int 
 */
int ft_putnbr_u(int n);
int ft_hexadecimal(int n, int max);
int	ft_hexadecimal_u(size_t number, int max);
int ft_putptr(size_t ptr);
#endif
