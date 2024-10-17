/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:48:19 by alerome2          #+#    #+#             */
/*   Updated: 2024/10/17 18:59:13 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/home/alerome2/Desktop/42/so_long/MLX42/include/MLX42/MLX42_Int.h"
#include <stdlib.h>
#include <unistd.h>

#define WIDTH 2000
#define HEIGHT 1000
#define TS 100

struct s_player
{
	int	x;
	int	y;
	int	key_collected;
	int	alive;
};

typedef struct s_counter
{
	int	i;
	int	j;
	int	a;
	int	b;
	int	c;
}	t_counter;

static mlx_image_t	*g_player;

//Map functions
char	**generate_map(void);
void	show_map(char **map);
void	free_map(char **map);
