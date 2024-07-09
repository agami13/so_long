/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_fill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 20:04:54 by ybouaoud          #+#    #+#             */
/*   Updated: 2024/07/08 23:00:14 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// void    collectibles_pos(t_map *map_info)
// {
//     int i = 0;
//     int j = 0;
//     while (map_info->map[i])
//     {
//         j = 0;
//         while (map_info->map[i][j])
//         {
//             if (map_info->map[i][j] == 'C')
//             {
//                 map_info->collectibles_x = j;
//                 map_info->collectibles_y = i;
//             }
//             j++;
//         }
//         i++;
//     }
// }

void    exit_pos(t_map *map_info)
{
    int i = 0;
    int j = 0;
    while (map_info->map[i])
    {
        j = 0;
        while (map_info->map[i][j])
        {
            if (map_info->map[i][j] == 'E')
            {
                map_info->exit_x = j;
                map_info->exit_y = i;
            }
            j++;
        }
        i++;
    }
}
void    player_pos(t_map *map_info)
{
    int i;
    int j;

    i = 0;
    while (map_info->map[i])
    {
        j = 0;
        while (map_info->map[i][j])
        {
            if (map_info->map[i][j] == 'P')
            {
                map_info->player_x = j;
                map_info->player_y = i;
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
    player_pos(map_info);
    exit_pos(map_info);
    map_info->moves = 0;
    map_info->x = 0;
    map_info->y = 0;
    return (map_info);
}