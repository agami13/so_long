/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:00:35 by ybouaoud          #+#    #+#             */
/*   Updated: 2024/07/15 22:33:17 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	get_x(char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'P')
				return (x);
			y++;
		}
		x++;
	}
	return (0);
}
int	get_y(char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'P')
				return (y);
			y++;
		}
		x++;
	}
	return (0);
}

int    floodfill(char **map, int x, int y, char target)
{
    if (x < 0 || x >= calculate_lines(map) || y < 0 || y >= (int)ft_strlen(map[0])
		|| map[x][y] == '1' || map[x][y] == '*')
		return (0);
	if (map[x][y] == target)
		return (1);
	map[x][y] = '*';
	return (floodfill(map, x + 1, y, target) || floodfill(map, x - 1, y,
			target) || floodfill(map, x, y + 1, target) || floodfill(map, x, y
			- 1, target));
}

int floodfill_collec(char **map, int x, int y, int *collectibles)
{
	int found;

    if (x < 0 || x >= calculate_lines(map) || y < 0 || y >= (int)ft_strlen(map[0])
        || map[x][y] == '1' || map[x][y] == '*' || map[x][y] == 'E')
        return (0);
    if (map[x][y] == 'C')
		(*collectibles)++;
    map[x][y] = '*';
    found = floodfill_collec(map, x + 1, y, collectibles) ||
                floodfill_collec(map, x - 1, y, collectibles) ||
                floodfill_collec(map, x, y + 1, collectibles) ||
                floodfill_collec(map, x, y - 1, collectibles);
    return (found);
}

int floodfill_app_collec(char **map, int x, int y)
{
    int collected;
    int total;

	collected = 0;	
	total = collectible_count(map);
	floodfill_collec(map, x, y, &collected);
    if (collected < total)
	{
        ft_putstr_fd("Error\nNot all collectibles can be collected!\n", 2);
        return (0);
    }
    return (1);
}

int    floodfill_app(char **map, int x, int y)
{
    int i;
    
    i = 0;
    if (!floodfill(map, x, y, 'E'))
    {
        ft_putstr_fd("Error\n", 2);
        ft_putstr_fd("No valid path found!\n", 2);
        while (map[i])
        {
            free(map[i]);
            i++;
        }
        free(map);
        return (0);
    }
    i = 0;
    while (map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
    return (1);
}
