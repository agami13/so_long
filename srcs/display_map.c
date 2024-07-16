/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 10:33:49 by ybouaoud          #+#    #+#             */
/*   Updated: 2024/07/16 01:23:18 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	map_width(char **map)
{
	int	i;
	int	j;
	int	width;

	i = 0;
	width = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			width = (j * TILE_SIZE) + TILE_SIZE;
			j++;
		}
		i++;
	}
	return (width);
}

int	map_height(char **map)
{
	int	i;
	int	height;

	i = 0;
	height = 0;
	while (map[i])
	{
		height = (i * TILE_SIZE) + TILE_SIZE;
		i++;
	}
	return (height);
}

void	collectibles_count(t_window *map)
{
	int		i;
	int		j;
	char	**map2;

	i = 0;
	map2 = map->map;
	while (map2[i])
	{
		j = 0;
		while (map2[i][j])
		{
			if (map2[i][j] == 'C')
				map->collectibles++;
			j++;
		}
		i++;
	}
}

void	put_map(t_window *game, char **map2, char *player_img)
{
	int	i;
	int	j;

	i = 0;
	while (map2[i])
	{
		j = 0;
		while (map2[i][j])
		{
			if (map2[i][j] == '1')
				put_img(game, "./imgs/tree.xpm", j * TILE_SIZE, i * TILE_SIZE);
			else if (map2[i][j] == '0')
				put_img(game, "./imgs/floor.xpm", j * TILE_SIZE, i * TILE_SIZE);
			else if (map2[i][j] == 'P')
				put_img(game, player_img, j * TILE_SIZE, i * TILE_SIZE);
			else if (map2[i][j] == 'E')
				put_img(game, "./imgs/portal.xpm",
					j * TILE_SIZE, i * TILE_SIZE);
			else if (map2[i][j] == 'C')
				put_img(game, "./imgs/coin.xpm", j * TILE_SIZE, i * TILE_SIZE);
			j++;
		}
		i++;
	}
}
