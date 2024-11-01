/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerome2 <alerome2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:48:19 by alerome2          #+#    #+#             */
/*   Updated: 2024/11/01 17:07:46 by alerome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MLX42/include/MLX42/MLX42_Int.h"
#include "../libft/inc/libft/libft.h"
#include "../libft/inc/get_next_line/get_next_line.h"
#include "../libft/inc/printf/ft_printf.h"

#define TS 100

typedef struct s_counter
{
	int	x;
	int	y;
	int	total_collectibles;
	int	collected;
	char **map;
	mlx_image_t	*player;
}	t_coords;

typedef struct s_textures
{
	mlx_texture_t	*wall;
	mlx_texture_t	*floor;
	mlx_texture_t	*exit;
	mlx_texture_t	*p;
	mlx_texture_t	*c_libft;
	mlx_texture_t	*c_printf;
	mlx_texture_t	*c_gnl;
	mlx_texture_t	*c_b2br;
	mlx_texture_t	*c_locked;
}	t_textures;

static mlx_image_t	*g_player; //static

//Map functions
char		**generate_map(void);
void		show_map(char **map);
void		free_map(char **map);
t_coords	*create_map(char *arg);
int			rows(char **map);

//Errors
int		check_chars(char **map);
int		check_rectangular(t_coords *map);
int		check_borders(char **map);
int		check_map(t_coords *map);
int		only_one_player_and_exit(char **map);

//Render
mlx_image_t	*render_map(char **map, void *mlx, t_textures *textures);

//Movements
void key_callback(mlx_key_data_t keydata, void *param);
void move_if_possible(t_coords *player, int option);

//Collectibles
int count_colectibles(t_coords *map);
void collect(t_coords *map);
void exit_map(t_coords *map);