/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 09:18:15 by ybouaoud          #+#    #+#             */
/*   Updated: 2024/07/09 04:07:40 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <math.h>

// struct for the game
typedef struct s_map
{
	void	*img;
	char	*path;
	int		x;
	int		y;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		moves;
	char	**map;
	struct  s_map *next;
}			t_map;

typedef struct s_window
{
	void	*mlx;
	void	*window;
	void	*img;
	char	*addr;
	int 	WIDTH;
	int 	HEIGHT;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} 			t_window;

// typedef struct s_long
// {
// 	char	**map;
// 	int x;
// 	int y;
// 	t_map	*map_info;
// }			t_long;


// macros
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define TILE_SIZE 32
// #define MLX_SYNC_IMAGE_WRITABLE		1
// #define MLX_SYNC_WIN_FLUSH_CMD		2
// #define MLX_SYNC_WIN_CMD_COMPLETED	3

// window functions
void    put_img(t_window *game, char *path, int x, int y);
int     map_width(char **map);
int     map_height(char **map);
int		ft_action(int keycode, t_window *game);
void    display_win(t_map *map_info);
// void    display_map(t_window *game, t_map *map_info);
void    put_map(t_window *game, t_map *map);

// parsing functions
void	parse_map(char *argv, char **map);
void	check_map(char **map);
void	check_nonvalid(char **map);
void	check_arg(char *argv);
void	map_access(char *argv);
void	map_valid2(char **map, int exit, int player, int collectible);
void	map_valid3(int E, int player, int collectible);
void	map_valid(char **map);
void	ft_free(char **strs);
void 	read_helper(char *line, char **map, char *argv);
char	**map_reader(char *arv);
t_map	*struct_filler(char **map);
void    player_pos(t_map *map_info);
void    exit_pos(t_map *map_info);
// void	map_blocked(char **map);


char	*read_map(char *argv);


int		calculate_lines(char **map);

#endif