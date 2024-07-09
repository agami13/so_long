/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 10:33:49 by ybouaoud          #+#    #+#             */
/*   Updated: 2024/07/09 04:09:04 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int     map_width(char **map)
{
    int i = 0;
    int j = 0;
    int width = 0;

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

int     map_height(char **map)
{
    int i = 0;
    int height = 0;

    while (map[i])
    {
        height = (i * TILE_SIZE) + TILE_SIZE;
        i++;
    }
    return (height);
}
void    put_map(t_window *game, t_map *map)
{
    int i = 0;
    int j;
    char    **map2;

    map2 = map->map;
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
                put_img(game, "./imgs/front.xpm", j * TILE_SIZE, i * TILE_SIZE);
            else if (map2[i][j] == 'E')
                put_img(game, "./imgs/portal.xpm", j * TILE_SIZE, i * TILE_SIZE);
            else if (map2[i][j] == 'C')
                put_img(game, "./imgs/coin.xpm", j * TILE_SIZE, i * TILE_SIZE);
            j++;
        }
        i++;
    }
}
