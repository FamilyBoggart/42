/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:48:19 by alerome2          #+#    #+#             */
/*   Updated: 2024/10/25 19:58:09 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/home/alerome2/Desktop/42/so_long/MLX42/include/MLX42/MLX42_Int.h"
#include "../libft/inc/libft/libft.h"
#include "../libft/inc/get_next_line/get_next_line.h"
#include "../libft/inc/printf/ft_printf.h"

#define WIDTH 2000
#define HEIGHT 1000
#define TS 100

typedef struct s_counter
{
	int	x;
	int	y;
}	t_coords;

typedef struct s_textures
{
	mlx_texture_t	*wall;
	mlx_texture_t	*floor;
	mlx_texture_t	*exit;
	mlx_texture_t	*player;
	mlx_texture_t	*c_libft;
	mlx_texture_t	*c_printf;
	mlx_texture_t	*c_gnl;
	mlx_texture_t	*c_locked;
}	t_textures;

static mlx_image_t	*g_player;

//Map functions
char	**generate_map(void);
void	show_map(char **map);
void	free_map(char **map);
void	create_map(char *arg, void *mlx, t_textures *textures);
int		rows(char **map);

//Errors
int		check_chars(char **map);
int		check_rectangular(char **map);
int		check_borders(char **map);
int		check_map(char **arg);
int		only_one_player_and_exit(char **map);

//Render
void	render_map(char **map, void *mlx, t_textures *textures);

//Movements
void	key_movements(void *param);