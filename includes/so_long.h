/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 09:18:15 by ybouaoud          #+#    #+#             */
/*   Updated: 2024/04/26 12:46:13 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/minilibx-linux/mlx.h"
# include "../libft/libft.h"

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

char	*read_map(char *argv);


int		calculate_lines(char **map);

#endif