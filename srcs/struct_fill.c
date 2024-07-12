/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_fill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 20:04:54 by ybouaoud          #+#    #+#             */
/*   Updated: 2024/07/12 01:32:31 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void player_pos(t_window *game, char **map)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'P')
            {
                game->x = j;
                game->y = i;
            }
            j++;
        }
        i++;
    }
}

t_map	*struct_filler(char **map)
{
    t_map *map_info;
    
    map_info = malloc(sizeof(t_map));
    map_info->map = map;
    map_info->moves = 0;
    map_info->x = 0;
    map_info->y = 0;
    return (map_info);
}