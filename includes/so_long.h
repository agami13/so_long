/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 09:18:15 by ybouaoud          #+#    #+#             */
/*   Updated: 2024/04/27 15:58:45 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <math.h>

// struct for the game
typedef struct s_long
{
	void	*mlx;
	void	*window;
	void	*img;
	char	*addr;
	char	**map;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
	int		x;
	int		y;
	int		player;
	int		collectible;
	int		exit;
	int		moves;
}			t_long;

// macros
# define WIDTH 800
# define HEIGHT 800
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100

// window functions
void	display_win(t_long *game);
void	display_map(t_long *game, char **map);
void	display_player(t_long *game, char **map);
void	display_collectible(t_long *game, char **map);
void	display_exit(t_long *game, char **map);
void	display_background(t_long *game, char **map);
void	display_square(t_long *game, int x, int y, int color);
void	display_circle(t_long *game, int x, int y, int color);
void	display_triangle(t_long *game, int x, int y, int color);

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
void	map_blocked(char **map);
// void	map_blocked(char **map);

char	*read_map(char *argv);


int		calculate_lines(char **map);

#endif